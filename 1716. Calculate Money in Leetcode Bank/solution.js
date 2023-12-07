var totalMoney = function (n) {
  // Calculate the number of complete weeks by using Math.floor to round down the division of n by 7 and store it in a constant named week_count
  const week_count = Math.floor(n / 7);
  // Calculate the number of remaining days by using the modulo operator to get the remainder of the division of n by 7 and store it in a constant named remaining_days
  const remaining_days = n % 7;

  // Initialize a variable named total to store the total money and set it to zero
  let total = 0;
  // Calculate the contribution from the complete weeks by using the formula for the sum of an arithmetic series with a common difference of 7 and a first term of 28, and add it to the total variable
  // This is equivalent to finding the sum of the money saved on each Sunday of the complete weeks
  total += ((week_count * (week_count - 1)) / 2) * 7;
  // Calculate the contribution from the complete weeks by multiplying the week_count by 28 and add it to the total variable
  // This is equivalent to finding the sum of the extra money saved on each Monday of the complete weeks
  total += week_count * 28;
  // Calculate the contribution from the remaining days by using the formula for the sum of an arithmetic series with a common difference of 1 and a first term of week_count + 1, and add it to the total variable
  // This is equivalent to finding the sum of the money saved on each day of the last incomplete week
  total +=
    (remaining_days * (remaining_days + 1)) / 2 + week_count * remaining_days;

  // Return the total variable as the final answer
  return total;
};

/* The time complexity = O(1), because the calculations are done in constant time and do not depend on the value of n. 
The space complexity = O(1), because no extra space is used apart from the input parameter and some variables. */
