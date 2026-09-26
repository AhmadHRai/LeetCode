#include <immintrin.h>

#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

template <typename To>
inline static constexpr auto cast =
    []<typename From> [[nodiscard, gnu::always_inline]] (From&& v) noexcept
{
    return static_cast<To>(std::forward<From>(v));
};

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// NOLINTBEGIN
static constexpr u64 BIAS = 0x6060606060606060ull, EXT = 0x1F1F1F1F1F1F1F1Full;
[[gnu::hot, gnu::target("bmi2")]]
inline u64 packStr(const std::string& s) noexcept
{
    const char* c8 = s.c_str();
    u8 n8 = s.length() & 0xFF;
    u8 sh = 50;
    u64 r = 0;
    if (n8 >= 8)
    {
        const u64 qw = *reinterpret_cast<const u64*>(c8) - BIAS;
        sh -= 40;
        r += _pext_u64(__builtin_bswap64(qw), EXT) << sh;
        c8 += 8;
        n8 -= 8;
    }
    if (n8 >= 4)
    {
        const u32 dw = *reinterpret_cast<const u32*>(c8) - (BIAS & 0xFFFFFFFFu);
        sh -= 20;
        r += u64{_pext_u32(__builtin_bswap32(dw), EXT & 0xFFFFFFFFu)} << sh;
        c8 += 4;
        n8 -= 4;
    }
    if (n8 >= 2)
    {
        const u16 w = *reinterpret_cast<const u16*>(c8) - (BIAS & 0xFFFFu);
        sh -= 10;
        r += u64{_pext_u32(__builtin_bswap32(w) >> 16, EXT & 0xFFFFu)} << sh;
        c8 += 2;
        n8 -= 2;
    }
    if (n8)
    {
        sh -= 5;
        r += (cast<u64>(*c8) - (BIAS & 0xFFu)) << sh;
        c8 += 1;
        n8 -= 1;
    }
    return r;
}

[[gnu::hot, gnu::target("bmi2")]]
inline std::string unpackStr(const u64 v) noexcept
{
    std::string r(10, '\0');
    char* c8 = r.data();
    *reinterpret_cast<u64*>(c8) =
        __builtin_bswap64(_pdep_u64(v >> 10, EXT)) + BIAS;
    *reinterpret_cast<u16*>(c8 + 8u) =
        __builtin_bswap32(
            cast<u32>(_pdep_u32(cast<u32>(v), EXT & 0xFFFFu) + (BIAS & 0xFFFFu))
            << 16) &
        0xFFFF;
    const auto end = r.find(BIAS & 0xFFu);
    if (end != std::string::npos) r.resize(end);
    return r;
}
// NOLINTEND
#ifndef LC_LOCAL_BUILD
auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();
#endif

struct HashTableStorage
{
    struct Entry
    {
        u64 key;
        u64 value;
    };

    inline static Entry entries[1 << 17];
    inline static Entry missing{};
    inline static u64 bits[(1 << 17) / 64];

    [[gnu::always_inline, gnu::no_sanitize_address]] static u32 hash(
        u64 key) noexcept
    {
        u64 z = key + 0x9e3779b97f4a7c15ULL;
        z = (z ^ (z >> 30U)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27U)) * 0x94d049bb133111ebULL;
        return cast<u32>(z >> 32U);
    }

    [[gnu::always_inline, gnu::no_sanitize_address]] static u64 lookup(
        u64 key,
        u32 mask) noexcept
    {
        // Query-built tables already contain every key the renderer can
        // request.
        u32 i = hash(key) & mask;
        while (entries[i].key && entries[i].key != key) i = (i + 1) & mask;
        return entries[i].value;
    }
};

template <u32 capacity, bool use_bits>
struct HashTable : HashTableStorage
{
    [[gnu::always_inline, gnu::no_sanitize_address]] HashTable() noexcept
    {
        if constexpr (use_bits)
        {
            std::memset(bits, 0, std::max(1u, capacity / 64) * sizeof(u64));
        }
        else
        {
            std::memset(entries, 0, capacity * sizeof(Entry));
        }
    }

    [[gnu::always_inline, gnu::no_sanitize_address]] Entry& slot(
        u64 key,
        bool insert = false) noexcept
    {
        u32 i = hash(key) & (capacity - 1);
        if constexpr (use_bits)
        {
            while ((bits[i >> 6] & (u64{1} << (i & 63))) &&
                   entries[i].key != key)
            {
                i = (i + 1) & (capacity - 1);
            }
            auto& word = bits[i >> 6];
            const auto mask = u64{1} << (i & 63);
            if (!(word & mask))
            {
                if (!insert)
                {
                    return missing;
                }
                entries[i] = {key, 0};
                word |= mask;
            }
        }
        else
        {
            while (entries[i].key && entries[i].key != key)
            {
                i = (i + 1) & (capacity - 1);
            }
        }
        return entries[i];
    }
};

class Solution
{
public:
    // Pack up to ten lowercase letters in the shared 50-bit representation.
    template <size_t n>
    [[gnu::always_inline, gnu::target("bmi2")]] static inline u64 packFixed(
        const char* p) noexcept
    {
        if constexpr (n == 0)
        {
            return 0;
        }
        else if constexpr (n == 1)
        {
            return static_cast<u64>(*p - 'a' + 1) << 45;
        }
        else
        {
            constexpr size_t width = std::bit_floor(n);
            using Word = std::conditional_t<
                width == 8,
                u64,
                std::conditional_t<width == 4, u32, u16>>;
            Word word{};
            std::memcpy(&word, p, width);
            word = std::byteswap(
                static_cast<Word>(word - static_cast<Word>(BIAS)));
            const u64 packed = width == 8
                                   ? _pext_u64(word, EXT)
                                   : _pext_u32(word, static_cast<Word>(EXT));
            return (packed << (50 - 5 * width)) |
                   (packFixed<n - width>(p + width) >> (5 * width));
        }
    }
    [[gnu::hot, gnu::target("bmi2")]] static inline u64 packStr10(
        std::string_view s) noexcept
    {
        switch (s.size())
        {
        case 0:
            return 0;
        case 1:
            return packFixed<1>(s.data());
        case 2:
            return packFixed<2>(s.data());
        case 3:
            return packFixed<3>(s.data());
        case 4:
            return packFixed<4>(s.data());
        case 5:
            return packFixed<5>(s.data());
        case 6:
            return packFixed<6>(s.data());
        case 7:
            return packFixed<7>(s.data());
        case 8:
            return packFixed<8>(s.data());
        case 9:
            return packFixed<9>(s.data());
        case 10:
            return packFixed<10>(s.data());
        default:
            __builtin_unreachable();
        }
    }

    // Max length before more than capacity/2 distinct keys can fit;
    // shortest keys first: 26 cost 3, 676 cost 4, 17576 cost 5, then cost 6.
    inline static constexpr std::array<size_t, 17> query_lengths{
        2,
        5,
        8,
        14,
        26,
        50,
        105,
        233,
        489,
        1001,
        2025,
        4396,
        9516,
        19756,
        40236,
        81196,
        100000};
    // For length bucket [2^(i-1), 2^i-1], max output is 10*(L/3)+L%3,
    // since a three-character placeholder can expand to ten characters;
    // L <= 100000.
    inline static constexpr std::array<size_t, 18> output_reserves{
        0,
        1,
        10,
        21,
        50,
        101,
        210,
        421,
        850,
        1701,
        3410,
        6821,
        13650,
        27301,
        54610,
        109221,
        218450,
        333331};

    [[gnu::no_sanitize_address]] static std::string_view
    consume(std::string_view s, size_t& i, char until) noexcept
    {
        size_t begin = i;
        i = s.find(until, i);
        return s.substr(begin, i - begin);
    }

    [[gnu::no_sanitize_address]] static std::string decode(
        u32 mask,
        std::string_view key) noexcept
    {
        const auto value = HashTableStorage::lookup(packStr10(key), mask);
        return value ? unpackStr(value) : "?";
    }

    template <u32 capacity, bool query_map>
    [[gnu::no_sanitize_address]] static u32 build(
        std::string_view s,
        const std::vector<std::vector<std::string>>& knowledge) noexcept
    {
        HashTable<capacity, query_map> m;
        if constexpr (query_map)
        {
            for (size_t i = s.find('('); i != s.npos; i = s.find('(', i + 1))
            {
                m.slot(packStr10(consume(s, ++i, ')')), true);
            }
        }

        for (auto& t : knowledge)
        {
            auto key = packStr(t[0]);
            auto& entry = m.slot(key, !query_map);
            if constexpr (query_map)
            {
                if (entry.key) entry.value = packStr(t[1]);
            }
            else
            {
                entry = {key, packStr(t[1])};
            }
        }

        return capacity - 1;
    }

    template <bool query_map>
    [[gnu::no_sanitize_address]] static u32 dispatch(
        std::string_view s,
        const std::vector<std::vector<std::string>>& knowledge,
        size_t count) noexcept
    {
        constexpr auto fns = []<size_t... i>(std::index_sequence<i...>)
        {
            return std::array{build<1 << i, query_map>...};
        }(std::make_index_sequence<18>{});
        size_t index{};
        if constexpr (query_map)
        {
            index = static_cast<size_t>(
                std::ranges::lower_bound(query_lengths, count) -
                query_lengths.begin());
        }
        else
        {
            index =
                cast<size_t>(std::min(17, std::bit_width(count + count / 2)));
        }
        return fns[index](s, knowledge);
    }

    [[gnu::no_sanitize_address]] std::string evaluate(
        std::string_view s,
        const std::vector<std::vector<std::string>>& knowledge) const noexcept
    {
        const size_t first = s.find('(');
        if (first == std::string_view::npos) return std::string{s};
        const size_t last = static_cast<size_t>(
            static_cast<const char*>(::memrchr(s.data(), ')', s.size())) -
            s.data());
        const size_t length = last - first + 1;
        const auto prefix = s.substr(0, first);
        const auto suffix = s.substr(last + 1);
        s = s.substr(first, length);
        const u32 mask = knowledge.size() < length
                             ? dispatch<false>(s, knowledge, knowledge.size())
                             : dispatch<true>(s, knowledge, length);

        std::string r;
        r.reserve(
            prefix.size() + suffix.size() +
            output_reserves[cast<size_t>(std::bit_width(length))]);
        if (!prefix.empty()) r += prefix;
        size_t i = 0, n = s.size();

        while (i < n)
        {
            r += consume(s, i, '(');
            if (i < n)
            {
                ++i;  // '('
                r += decode(mask, consume(s, i, ')'));
                ++i;  // ')'
            }
        }

        r += suffix;
        return r;
    }
};
