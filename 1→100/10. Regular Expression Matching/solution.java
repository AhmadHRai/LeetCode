class Solution {
    public boolean isMatch(String s, String p) {

        if (s == null || p == null) {
            return false;
        }
        // Use a more descriptive name for the boolean array
        boolean[][] match = new boolean[s.length() + 1][p.length() + 1];
        match[0][0] = true;
        // Use a for-each loop to iterate over the characters in p
        int index = 0;
        for (char pc : p.toCharArray()) {
            if (pc == '*' && match[0][index - 1]) {
                match[0][index + 1] = true;
            }
            index++;
        }
        // Use another for-each loop to iterate over the characters in s
        int i = 1;
        for (char sc : s.toCharArray()) {
            // Use a switch statement to handle the different cases of the pattern character
            int j = 1;
            for (char pc : p.toCharArray()) {
                switch (pc) {
                    case '.':
                        match[i][j] = match[i - 1][j - 1];
                        break;
                    case '*':
                        if (p.charAt(j - 2) != sc && p.charAt(j - 2) != '.') {
                            match[i][j] = match[i][j - 2];
                        } else {
                            match[i][j] = match[i][j - 1] || match[i - 1][j] || match[i][j - 2];
                        }
                        break;
                    default:
                        // Use the charAt method directly on the string s and p
                        match[i][j] = sc == pc && match[i - 1][j - 1];
                }
                j++;
            }
            i++;
        }
        return match[s.length()][p.length()];
    }
}

/* 
Time complexity: O(mn) where m is the length of the string s and n is the length of the pattern p. The function fills a two-dimensional boolean array of size (m + 1) x (n + 1) by 
looping through each character in s and p once and performing constant time operations.
Space complexity: O(mn) where m is the length of the string s and n is the length of the pattern p. The function creates a two-dimensional boolean array of size (m + 1) x (n + 1) 
to store the matching results for each substring and subpattern.
 */