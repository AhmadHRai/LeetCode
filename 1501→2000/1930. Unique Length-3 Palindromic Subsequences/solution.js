/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function (s) {
    let res = 0;
    const uniq = new Set(s);

    for (const c of uniq) {
        const start = s.indexOf(c);
        const end = s.lastIndexOf(c);

        if (start < end) {
            res += new Set(s.slice(start + 1, end)).size;
        }
    }

    return res;
};
