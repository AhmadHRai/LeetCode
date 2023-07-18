/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
  // Use a bitwise operation to check if the number is negative
  // If x is negative, the most significant bit will be 1, otherwise it will be 0
  // Return false if the number is negative
  if (x >> 31) {
    return false;
  }

  // Initialize two variables to store the reversed number and the original number
  let reversed = 0;
  let original = x;

  // Loop through the digits of x from right to left
  while (x > 0) {
    // Get the last digit of x by using the modulo operator
    const digit = x % 10;
    // Append the digit to the reversed number by multiplying it by 10 and adding the digit
    reversed = reversed * 10 + digit;
    // Remove the last digit of x by using the floor division operator
    x = Math.floor(x / 10);
  }

  // Return true if the original number and the reversed number are equal, false otherwise
  return original === reversed;
};

// Time complexity: O(log10(n)) where n is the value of x
// The function loops through each digit of x once and performs constant time operations

// Space complexity: O(1) where 1 is a constant
// The function uses a few variables of fixed size to store the number, the digit, and the reversed number
