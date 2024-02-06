var groupAnagrams = function (strs) {
  // Create an empty object to store the grouped anagrams
  let res = {};
  // Loop over the input array of strings
  for (let str of strs) {
    // Create an array of size 26, filled with 0, to represent the frequency of each letter in the string
    let count = new Array(26).fill(0);
    // Loop over the string and increment the corresponding element in the array
    for (let char of str) count[char.charCodeAt() - 97]++;
    // Join the array elements with "#" as a separator to form a unique key for the string
    let key = count.join("#");
    // If the key already exists in the object, add the string to the existing array
    // Otherwise, create a new array with the string as the only element
    res[key] ? res[key].push(str) : (res[key] = [str]);
  }
  // Return the values of the object, which are the arrays of grouped anagrams
  return Object.values(res);
};

/* 
Complexity:

    The time complexity of the code is O(nk), where n is the size of the input array and k is the maximum length of any string in the array. This is because we need to loop over 
    the array once, which takes O(n) time, and for each string, we need to loop over its characters, which takes O(k) time. The insertion and retrieval from the object are 
    constant time operations, so they do not affect the overall time complexity.

    The space complexity of the code is O(n), where n is the same as above. This is because we need to store the keys and the arrays of anagrams in the object, which takes O(n) 
    space. The array of frequencies also takes O(1) space, because it has a fixed size of 26. The space complexity does not depend on the length of the strings, but on the number 
    of distinct anagrams in the input array.
*/
