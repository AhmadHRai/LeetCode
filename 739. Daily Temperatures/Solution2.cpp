class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int>nge(n, 0); // initially all 0, stores distance between their next greater element and current temperature
        stack<int>st{};
        
		// move from right to left
        for(int i = n-1; i>=0; --i){
            // pop until we find next greater element to the right
			// since we came from right stack will have element from right only
			// s.top() is the index of elements so we put that index inside temperatures vector to check
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
				
            // if stack not empty, then we have some next greater element, 
			// so we take distance between next greater and current temperature
			// as we are storing indexes in the stack
            if(!st.empty())
                nge[i] = st.top()-i; // distance between next greater and current
            
			// push the index of current temperature in the stack,
			// same as pushing current temperature in stack
            st.push(i);
        }
        
        return nge;
    }
};

/* 
Approach
This solution is very similar to the first one, except for some minor differences in variable names and syntax.
The logic and the algorithm are the same, so the time and space complexity are also the same: O(n) for both.
The only difference is that this approach uses a vector nge to store the result, instead of res, and uses a stack st, instead of s.
this approach also uses a variable n to store the value of the current element, instead of accessing it directly from the array.
Therefore both solutions have the same time and space complexity: O(n) 
 */