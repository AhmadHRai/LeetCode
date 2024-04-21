import java.util.*;

class main{
    public static void main(String[] args) {
        Solution solution = new Solution();

        String[][] testCases = {
            {"This", "is", "an", "example", "of", "text", "justification."},
            {"What", "must", "be", "acknowledgment", "shall", "be"},
            {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"}
        };

        int[] maxWidths = {16, 16, 20};

        for (int i = 0; i < testCases.length; i++) {
            String[] words = testCases[i];
            int maxWidth = maxWidths[i];

            List<String> result = solution.fullJustify(words, maxWidth);

            System.out.println("Test Case " + (i + 1) + ":");
            for (String line : result) {
                System.out.println("\"" + line + "\"");
            }
            System.out.println();
        }
    }
}