/* 
https://leetcode.com/problems/bitwise-and-of-numbers-range/solutions/592288/100-memory-c-solution-with-explanation

since we are dealing with and(&) operator any presence of 0 with a 1 gives 0. We loop through the binary representation and in the lsbs of elements m and n if there is a 0 and a 1 then the resultant value is 0, so we shift the elements right till there are equal and count the increments made i.e for each of the shift till both the numbers become equal. When both elements m and n are equal we get the value in the lsb as 1. From the above binary representation of the numbers and range we make the following observations:
1. The third bit from lsb is common for all the three numbers in the range.
2. There are zeros in the first and second positions from the lsb so the resultant value will be 0 in that postion.
Count is a variable wich keeps a track of number of zeros from the lsb to the case of m==n.

The code is as following:
 */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        //  simple solution is to do bitwise and and return the sum. 
        //  for(int i=m;i<=n;i++)
        //      sum&=i;        
		//      return sum;
        while(m!=n)  // see till both numbers are equal
        {   // right shift both numbers by 1
            m>>=1; 
            n>>=1;
            count++;  // increment the count.
        }
		//count gives the number of zero places from the lsb so left shift m by count.
        return m<<count;
    }
};

/* 
Complexity:
    The time complexity of the rangeBitwiseAnd function is O(log(n)) and the space complexity is O(1). Here's why:
        Time Complexity (O(log(n))): The function uses a while loop that halves the values of m and n in each iteration until they become equal. Since each iteration reduces the size 
        of the numbers by half, the number of iterations is proportional to the number of times you can halve n until you reach 1. This is essentially the definition of the logarithm 
        base 2 of n, hence the time complexity is O(log(n)).
        
        Space Complexity (O(1)): The function uses a constant amount of space to store the variables m, n, and count. The space used does not grow with the size of the input m and n, 
        hence the space complexity is O(1). This means that the memory usage is constant regardless of the input size.

 */