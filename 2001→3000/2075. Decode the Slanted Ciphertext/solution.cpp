class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (rows == 1)
            return encodedText;

        int cols = n / rows;
        string res;
        res.reserve(n);

        for (int c = 0; c < cols; ++c) {
            int r = 0, j = c;
            while (r < rows && j < cols) {
                res += encodedText[r * cols + j];
                ++r;
                ++j;
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};
