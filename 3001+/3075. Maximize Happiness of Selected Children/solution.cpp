class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());
        int i = 0;
        long long res = 0;

        while(k--) {
            happiness[i] = max(happiness[i] - i, 0);
            res += happiness[i++];
        }

        return res;
    }
};


/*
Approach
    The problem aims to maximize the total happiness gained by selecting the happiest children within the given limit (k). It’s all about spreading the most happiness among the children! Let’s break down the approach used in the code:


    Sorting the Children: Just like picking the happiest children first, we sort the children in descending order of their happiness. This way, we can start with the happiest ones first!


    Selecting the Happiest Children: With a limited number of children we can select (k), we start selecting the happiest ones! Each time we select a child, we check if it makes us even happier. If it does, we select it; otherwise, we skip it.


    Adjusting Happiness Levels: As we select the children, we also adjust the happiness levels of the remaining children. We subtract 1 from their happiness, but only if they were initially positive.


    Summing Up the Happiness: After selecting our children, we sum up all the happiness from the children we’ve selected. That’s our total happiness!


Dry Run
    Let’s dry run the example step by step:
    Initial State:

    Happiness: [1, 2, 3]
    k = 2
    Total happiness sum = 0

    Step 1:

    Sort the happiness array in descending order: [3, 2, 1]
    Select the child with the highest happiness value (3).

    Subtract its index (0) from its happiness value: 3 - 0 = 3
    Add this to the total happiness sum: 0 + 3 = 3


    Decrease the happiness of the remaining children by 1: [2, 1, 0]
    Decrement k: k = 1

    Step 2:

    Select the child with the next highest happiness value (2).

    Subtract its index (1) from its happiness value: 2 - 1 = 1
    Add this to the total happiness sum: 3 + 1 = 4


    Decrease the happiness of the remaining child by 1: [1, 0, 0]
    Decrement k: k = 0

    Step 3:

    Since k has reached 0, we stop.
    The total happiness sum is 4.

    Final Output:

    Total happiness sum = 4

    So, the output is 4, as explained in the example.

Complexity

    Time complexity: O(nlogn+min(k,n))

    Space complexity: O(1)

    The time complexity is due to sorting the happiness array and then iterating over it. The space complexity is constant because we are not using any additional data structures that scale with the input size. The space used by the input array does not count towards the space complexity.  
*/