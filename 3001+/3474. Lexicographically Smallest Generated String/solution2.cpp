class Solution {
public:
    string generateString(string str1, string str2) {

        int L1 = str1.length();
        int L2 = str2.length();

        int N = L1 + L2 - 1;

        vector<bool> isFixed(N, false);

        string S(N, '?');

        for(int i = 0; i < L1; i++){

            if(str1[i] == 'T'){

                for(int j = 0; j < L2; j++){

                    if(S[i+j] != '?' && S[i+j] != str2[j]){

                        return "";
                    }

                    S[i+j] = str2[j];
                    isFixed[i+j] = true;
                }
            }
        }

        for(int i = 0; i < N; i++){

            if(S[i] == '?'){

                S[i] = 'a';
            }
        }

        for(int i = 0; i < L1; i++){

            if(str1[i] == 'F' && S.compare(i, L2, str2) == 0){

                bool changed = false;

                for(int j = i + L2 - 1; j >= i; j--){

                    if(!isFixed[j]){

                        S[j] = 'b';
                        isFixed[j] = true;
                        changed = true;
                        break;
                    }
                }

                if(!changed) return "";
            }
        }

        return S;
    }
};
