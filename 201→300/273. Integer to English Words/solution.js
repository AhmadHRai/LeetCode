/**
 * Converts a number into its English words.
 * @param {number} num - The number to be converted to words.
 * @return {string} - The English words representing the number.
 */
var numberToWords = function (num) {
  if (num === 0) {
    return "Zero"; // If the number is 0, return "Zero"
  }

  if (num <= 20) {
    return translations.get(num); // If the number is between 1 and 20, directly return the corresponding word
  }

  let result = []; // Initialize an empty array to store parts of the English representation

  // Iterate over the predefined translation map
  for (let [value, translation] of translations) {
    const times = Math.floor(num / value); // Determine how many times the current value fits into the number

    if (times === 0) {
      continue; // If the current value doesn't fit into the number, skip it
    }

    num -= times * value; // Subtract the corresponding part from the number

    if (times === 1 && value >= 100) {
      result.push("One", translation); // For hundreds, append "One" and the corresponding word
      continue;
    }

    if (times === 1) {
      result.push(translation); // For other values, append just the corresponding word
      continue;
    }

    result.push(numberToWords(times), translation); // For larger values, recursively call numberToWords for the times part
  }

  return result.join(" "); // Join all parts of the result array into a string and return it
};

// Predefined translation map for values and their corresponding English words
const translations = new Map([
  [1000000000, "Billion"],
  [1000000, "Million"],
  [1000, "Thousand"],
  [100, "Hundred"],
  [90, "Ninety"],
  [80, "Eighty"],
  [70, "Seventy"],
  [60, "Sixty"],
  [50, "Fifty"],
  [40, "Forty"],
  [30, "Thirty"],
  [20, "Twenty"],
  [19, "Nineteen"],
  [18, "Eighteen"],
  [17, "Seventeen"],
  [16, "Sixteen"],
  [15, "Fifteen"],
  [14, "Fourteen"],
  [13, "Thirteen"],
  [12, "Twelve"],
  [11, "Eleven"],
  [10, "Ten"],
  [9, "Nine"],
  [8, "Eight"],
  [7, "Seven"],
  [6, "Six"],
  [5, "Five"],
  [4, "Four"],
  [3, "Three"],
  [2, "Two"],
  [1, "One"],
]);

/*
  Approach:
  1. The solution uses a recursive approach to break down the number into parts based on the predefined value translations.
  2. It starts by checking for numbers less than or equal to 20, directly using the translation map.
  3. For numbers greater than 20, it iterates over the map and repeatedly divides the number by the current value, reducing the number step by step.
  4. The solution handles each part of the number (billions, millions, thousands, etc.) by appending the appropriate word to the result.
  
  Complexity Analysis:
  1. Time Complexity: O(log n) - The solution reduces the number by dividing by powers of 10, so the number of iterations depends on the number's size in terms of powers of 10.
  2. Space Complexity: O(1) - The space used is constant as the solution only stores a few variables and the result array, which does not grow with the input number.
  */
