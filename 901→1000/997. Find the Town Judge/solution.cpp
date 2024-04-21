class Solution {
public:
    int findJudge(int n, vector<vector<int>> trust) {
        if (trust.size() == 0 && n == 1) 
            return 1;
        vector<int> count(n + 1);
        for (auto person : trust) {
            //count[person[0]]--; decrements the trust count of the first person in the pair. This is done because if the first person trusts the second person, it means that the first person does not trust themselves.
            count[person[0]]--;
            //count[person[1]]++; increments the trust count of the second person in the pair. This is done because if the first person trusts the second person, it means that the second person is trusted by the first person.
            count[person[1]]++;
        }

        for (int person = 0; person < count.size(); person++) {
            // check if there is a person who is trusted by everyone except themselves (n-1 people) and if such person exists it returns the index of that person.
            if (count[person] == n - 1) return person;
        }
        return -1;
    }
};

/* 
Explanation
    In graph theory, we say the outdegree of a vertex (person) is the number of directed edges going out of it. For this graph, the outdegree of the vertex represents the number of other people that person trusts.
    Likewise, we say that the indegree of a vertex (person) is the number of directed edges going into it. So here, it represents the number of people trusted by that person.
    SAME CONCEPT WE WILL USE BELOW
    decrements the trust count of the first person in the pair. This is done because if the first person trusts the second person, it means that the first person does not trust themselves.
    increments the trust count of the second person in the pair. This is done because if the first person trusts the second person, it means that the second person is trusted by the first person.
    check if there is a person who is trusted by everyone except themselves (n-1 people) and if such person exists it returns the index of that person.

Approach

    Initialize an empty array count of size n+1 to keep track of the number of people that trust or are trusted by a particular person.
    Iterate through the trust array, for each pair of people, decrement the trust count of the first person and increment the trust count of the second person.
    Iterate through the count array, for each person, check if their trust count is equal to n-1, if yes return that person's index, as that person is the judge.
    If no such person is found, return -1 as no judge exists.

Complexity

    Time complexity: O(n)
    Space complexity: O(n)
 */