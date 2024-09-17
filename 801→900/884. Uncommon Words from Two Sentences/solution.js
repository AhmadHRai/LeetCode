/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
function uncommonFromSentences(s1, s2) {
    // Function to count occurrences of words in a sentence
    function countWords(sentence) {
        const wordCount = {}; // Object to store word counts
        const words = sentence.split(' '); // Split the sentence into words
        for (const word of words) {
            // Increment the count for each word
            wordCount[word] = (wordCount[word] || 0) + 1;
        }
        return wordCount; // Return the word count object
    }

    // Count words in both sentences
    const count1 = countWords(s1); // Word counts from the first sentence
    const count2 = countWords(s2); // Word counts from the second sentence

    const uncommonWords = []; // Array to store uncommon words

    // Check words in s1 for uncommonness
    for (const word in count1) {
        // A word is uncommon if it appears once in s1 and not at all in s2
        if (count1[word] === 1 && !count2[word]) {
            uncommonWords.push(word); // Add to uncommon words
        }
    }

    // Check words in s2 for uncommonness
    for (const word in count2) {
        // A word is uncommon if it appears once in s2 and not at all in s1
        if (count2[word] === 1 && !count1[word]) {
            uncommonWords.push(word); // Add to uncommon words
        }
    }

    return uncommonWords; // Return the list of uncommon words
}

/*
Approach:
1. Define a helper function `countWords` to count occurrences of each word in a given sentence.
2. Split the sentence into words and populate an object with the word counts.
3. Count the words in both sentences using this helper function.
4. Iterate through the word counts of both sentences:
   - A word is considered uncommon if it appears exactly once in one sentence and does not appear in the other.
5. Collect and return all uncommon words from both sentences.

Time Complexity:
- O(n + m), where `n` is the number of words in `s1` and `m` is the number of words in `s2`. Each word is processed once.

Space Complexity:
- O(n + m) for storing the counts of words in two objects. In the worst case, each word could be unique.
*/
