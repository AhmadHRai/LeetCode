# Example Explanation

Let's create a step-by-step explanation using tables:

### Step 1: Initialize Character Counts Array

| Character | a   | b   | c   | d   | ... | z   |
| --------- | --- | --- | --- | --- | --- | --- |
| Counts    | 1   | 2   | 0   | 3   | ... | 0   |

Initialize an array `counts` to store the count of each character in `chars`.

### Step 2: Update Counts Array

Iterate through each character in `chars` and update the counts.

| Character | a   | b   | c   | d   | ... | z   |
| --------- | --- | --- | --- | --- | --- | --- |
| Counts    | 2   | 3   | 1   | 4   | ... | 1   |

### Step 3: Check Words

For each word in `words`, check if it can be formed using the counts of characters in `chars`.

| Word   | canForm |
| ------ | ------- |
| "cat"  | true    |
| "bt"   | false   |
| "hat"  | true    |
| "tree" | false   |

### Step 4: Calculate Lengths

If a word can be formed, add its length to the result.

| Word   | canForm | Length |
| ------ | ------- | ------ |
| "cat"  | true    | 3      |
| "bt"   | false   | 0      |
| "hat"  | true    | 3      |
| "tree" | false   | 0      |

### Step 5: Calculate Result

Return the sum of lengths.

[3 + 0 + 3 + 0 = 6]

This gives the final result.

# Intuition

The goal is to find the sum of lengths of strings that can be formed using the characters from the given string `chars`. We need to check for each string in `words` if it can be formed from the characters in `chars`.

# Approach

1.  Initialize an array `counts` to store the count of each character in `chars`.
2.  Iterate through each character in `chars` and update the counts.
3.  For each string in `words`, check if it can be formed using the counts of characters in `chars`.
4.  If a string can be formed, add its length to the result.
5.  Return the final result.

# Complexity

- Let `m` be the total number of characters in all words, and `n` be the number of words.
- The time complexity is O(m + n), where m is the length of the `chars` string, and n is the length of the `words` array.
- The space complexity is O(1) as the size of the array (26 for lowercase English letters) is constant.
