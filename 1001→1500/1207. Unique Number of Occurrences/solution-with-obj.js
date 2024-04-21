// Declare a function named uniqueOccurrences that takes an array of numbers as a parameter and returns a boolean
var uniqueOccurrences = function (arr) {
  // Declare an object named occurrences to store the frequency of each number in the array
  let occurrences = {};

  // Loop through each number in the array
  for (let number of arr) {
    // If the number is already a key in the occurrences object
    if (occurrences[number]) {
      // Increment its value by one
      occurrences[number]++;
    }
    // Otherwise (i.e. the number is not a key in the occurrences object)
    else {
      // Set its value to one
      occurrences[number] = 1;
    }
  }

  // Get an array of the values of the occurrences object
  const values = Object.values(occurrences);
  // Create a set from the values array and get its size
  const uniqueLength = new Set(values).size;

  // Return true if the length of the values array is equal to the size of the set
  // This means that all the values are unique
  return values.length === uniqueLength;
};

/* 
Complexity:
    The time complexity is O(n), where n is the length of the array. This is because the code loops through each element in the array, which takes O(n) time, and performs 
    constant-time operations on the object and the set, such as accessing, updating, and checking values.

    The space complexity is O(n), as the code uses an object and a set to store the frequency and the uniqueness of the values in the array. The object and the set can have at 
    most n elements, where n is the length of the array. Therefore, the overall space complexity is O(n).
*/
