/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
  // Use a bitwise operation to get the sign of x
  // If x is negative, sign will be -1, otherwise sign will be 1
  const sign = (x >> 31) | 1;

  // Get the absolute value of x and convert it to a string
  const str = Math.abs(x).toString();

  // Initialize an empty string to store the reversed digits
  let reversed = "";

  // Loop through the string from the end to the start
  for (let i = str.length - 1; i >= 0; i--) {
    // Append each digit to the reversed string
    reversed += str[i];
  }

  // Convert the reversed string to a number and multiply it by the sign
  const result = Number(reversed) * sign;

  // Check if the result is within the 32-bit signed integer range
  // Use the hexadecimal representation of the range limits for clarity
  if (result < -0x80000000 || result > 0x7fffffff) {
    return 0; // Return 0 if the result is outside the range
  }

  return result;
};

// Time complexity: O(n) where n is the number of digits in x
// The function loops through each digit in x once and performs constant time operations

// Space complexity: O(n) where n is the number of digits in x
// The function creates a string of length n to store the reversed digits
