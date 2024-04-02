/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
function isIsomorphic(s, t) {
  // Check if the lengths of the two strings are equal. If not, they cannot be isomorphic.
  if (s.length !== t.length) return false;

  // Initialize two hash maps to track the mapping between characters in the two strings.
  const mapa = new Map();
  const mapb = new Map();

  // Iterate over each character in the strings.
  for (let i = 0; i < s.length; i++) {
    // For each character in 's', check if it has been seen before.
    if (mapa.has(s[i])) {
      // If the character has been seen before, check if its mapping matches the current character in 't'.
      if (mapa.get(s[i]) !== t[i]) {
        // If the mappings do not match, the strings are not isomorphic.
        return false;
      }
    } else {
      // If the character has not been seen before, add it to the map with its corresponding character in 't'.
      mapa.set(s[i], t[i]);
    }

    // For each character in 't', check if it has been seen before.
    if (mapb.has(t[i])) {
      // If the character has been seen before, check if its mapping matches the current character in 's'.
      if (mapb.get(t[i]) !== s[i]) {
        // If the mappings do not match, the strings are not isomorphic.
        return false;
      }
    } else {
      // If the character has not been seen before, add it to the map with its corresponding character in 's'.
      mapb.set(t[i], s[i]);
    }
  }

  // If the loop completes without finding any mismatches, the strings are isomorphic.
  return true;
}

/* 
Approach Summary

    This solution uses two hash maps to track the mapping between characters in the two strings. It iterates through the strings, 
    updating the maps with the current character mappings. If a character is encountered for the first time, it is added to the map. If 
    a character has been seen before, its mapping is checked against the current character. If the mappings do not match, the function 
    returns false, indicating that the strings are not isomorphic. If all characters are mapped correctly, the function returns true.

Time Complexity Analysis

    The time complexity is O(n), where n is the length of the strings. This is because each character in the strings is visited once.

Space Complexity Analysis

    The space complexity is O(1), assuming the character set is fixed (e.g., ASCII). The space complexity is constant because the size 
    of the hash maps does not grow with the size of the input strings.

 */
