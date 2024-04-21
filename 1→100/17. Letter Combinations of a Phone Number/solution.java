class Solution {
    public List<String> letterCombinations(String digits) {
        // Initialize an empty LinkedList to store the generated combinations
        LinkedList<String> ans = new LinkedList<String>();
        
        // If the input string is empty, return the empty list
        if(digits.isEmpty()) return ans;
        
        // Define the mapping from digits to letters on the phone keypad
        String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // Start with an empty string as the first combination
        ans.add("");
        
        // Loop until the length of the combinations in ans matches the length of digits
        while(ans.peek().length() != digits.length()){
            // Remove the first combination from ans
            String remove = ans.remove();
            
            // Retrieve the corresponding letters for the current digit from the mapping array
            String map = mapping[digits.charAt(remove.length()) - '0'];
            
            // Iterate over each letter in the retrieved string
            for(char c: map.toCharArray()){
                // Append the letter to the current combination and add the new combination back to ans
                ans.addLast(remove + c);
            }
        }
        
        // Return the list of generated combinations
        return ans;
    }
}

/* 
Approach
    The solution uses a breadth-first search (BFS) approach to generate all possible letter combinations. It starts with an empty string and iteratively appends each 
    letter that the current digit can represent to the current combination. This process continues until all digits have been processed, resulting in all possible 
    combinations of letters.

Complexity Analysis
    Time Complexity: The time complexity of this solution is O(N * 4^M), where N is the number of digits in the input string, and M is the average number of letters that 
        each digit can represent. This is because for each digit, we generate up to 4 (the maximum number of letters a digit can represent) new combinations, and we do 
        this for all N digits.
    
    Space Complexity: The space complexity is also O(N * 4^M) because in the worst case, we might need to store all possible combinations in the ans list.
        
Comments
    The mapping array uses "0" as the first element, which is not a valid digit on a phone keypad. This might be a mistake or a placeholder, but it should be corrected 
    to match the actual mapping of digits to letters on a phone keypad.
    
    The solution assumes that the input string digits only contains valid digits. If the input string can contain invalid characters, additional error handling would be necessary.
    
    The solution uses a LinkedList for ans because it allows efficient removal of the first element and addition of new elements at the end. This is crucial for the BFS approach used in the solution.

 */