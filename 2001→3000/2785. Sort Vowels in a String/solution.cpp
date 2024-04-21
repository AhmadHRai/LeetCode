class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vow;
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U') { // condition to check for vowel
                vow.push_back(s[i]);
                pos.push_back(i); //storing positions of vowel 
            }
        }
        sort(vow.begin(),vow.end());
        string answer = s;
        for(int i=0;i<pos.size();i++){
            answer[pos[i]] = vow[i];
        }
        return answer;
    }
};

/* 
Approach
    The approach is to first identify the vowels in the input string s and store them along with their positions in two separate vectors, vow and pos, respectively. Then, the code 
    sorts the vow vector to arrange the vowels in ascending order. After that, a new string answer is created, initially set to the same content as the input string s.

    Finally, the code replaces the characters at the positions stored in the pos vector with the sorted vowels from the vow vector. The resulting modified string with the sorted 
    vowels is returned as the output of the function.

Complexity
    Time complexity: O(n*logn)
    Space complexity: O(n)
 */