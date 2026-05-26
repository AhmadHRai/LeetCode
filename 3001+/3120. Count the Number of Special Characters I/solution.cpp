class Solution {
public:
    static int numberOfSpecialChars(string& word) {
        unsigned A[2];
        for(char c: word){
            bool isLower=c&(1<<5);
            A[isLower]|=(1<<(c&31));
        }
        return popcount(A[0]&A[1]);
    }
};
