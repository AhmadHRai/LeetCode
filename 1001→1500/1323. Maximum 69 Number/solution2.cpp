class Solution {
public:
    int maximum69Number (int num) {
        int firstSix = -1;
        int number = num;
        for(int i = 0; number > 0; i++){
            if(number % 10 == 6) {
                firstSix = i;
            }
            number /= 10;
        }
        return firstSix == -1 ? num : num + 3 * pow(10, firstSix);
    }
};