template <class T>
class DigitIterator
{
public:
    class iterator
    {
    public:
        using iterator_category = std::input_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const T*;
        using reference         = T;
        constexpr iterator() noexcept = default;
        constexpr T operator*() const noexcept { return z_ % base_; }
        constexpr iterator& operator++() noexcept { z_ /= base_; --left_; return *this; }
        constexpr iterator operator++(int) noexcept { iterator tmp = *this; ++*this; return tmp; }
        friend constexpr bool operator==(const iterator& a, const iterator& b) noexcept { return a.left_ == b.left_; }
        friend constexpr bool operator!=(const iterator& a, const iterator& b) noexcept { return !(a == b); }

    private:
        friend class DigitIterator;

        constexpr iterator(T z, T base, std::size_t left) noexcept
            : z_{z}, base_{base}, left_{left}
        {}

        T z_;
        T base_;
        std::size_t left_;
    };

    constexpr DigitIterator(T x, T base) noexcept
        : base_{base}
    {
        do
        {
            z_ = z_ * base + x % base;
            x /= base;
            ++size_;
        }
        while (x != 0);
    }

    constexpr iterator begin() const noexcept { return {z_, base_, size_}; }
    constexpr iterator end()   const noexcept { return {z_, base_, 0}; }

private:
    T z_{};
    T base_;
    std::size_t size_{};
};

class DigitTrie
{
    struct Node
    {
        std::array<Node*, 10> next;
        // bool is_leaf;
    };

    static constexpr std::size_t cap_ = 600'000;
    inline static std::array<Node, cap_> arena_;
    inline static std::size_t ptr_ = 0;
    inline static Node* free_ = nullptr;

    static constexpr Node* allocate()
    {
        Node* node;
        if (free_)
        {
            node = free_;
            free_ = node->next[0];
        }
        else if (ptr_ < cap_)
        {
            node = &arena_[ptr_++];
        }
        else
        {
            throw std::bad_alloc{};
        }
        for (auto& p : node->next)
            p = nullptr;
        // node->is_leaf = false;
        return node;
    }

    static constexpr void deallocate(Node* node) noexcept
    {
        node->next[0] = free_;
        free_ = node;
    }

public:
    constexpr DigitTrie() noexcept = default;

    void insert(int x)
    {
        if (!root_)
            root_ = allocate();

        Node* node = root_;
        for(int d : DigitIterator(x, 10))
        {
            if(node->next[d] == nullptr)
                node->next[d] = allocate();
            node = node->next[d];
        }
        // node->is_leaf = true;
    }

    std::size_t prefix_length(int x) noexcept
    {
        if (!root_) return 0;

        std::size_t len = 0;
        Node* node = root_;
        for(int d : DigitIterator(x, 10))
        {
            if(node->next[d] == nullptr)
                return len;
            node = node->next[d];
            ++len;
        }
        return len;
    }

private:
    Node* root_ = nullptr;
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        auto trie = DigitTrie();
        for (int x : arr2)
            trie.insert(x);

        int max_len = 0;
        for (int x : arr1)
            max_len = std::max<int>(max_len, trie.prefix_length(x));

        return max_len;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
