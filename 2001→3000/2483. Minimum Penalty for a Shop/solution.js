var bestClosingTime = function (customers) {
  const n = customers.length;

  // Calculate total number of customers
  let totalCustomers = 0;
  for (let i = 0; i < n; i++) {
    if (customers[i] === "Y") {
      totalCustomers++;
    }
  }

  let currentCustomers = 0;
  let minPenalty = n + 1; // Initialize with a value greater than maximum possible penalty
  let bestClosingHour = 0;

  // Iterate through each hour as potential closing time
  for (let hour = 0; hour <= n; hour++) {
    // Calculate penalty for the current closing hour
    const penalty =
      hour - currentCustomers + (totalCustomers - currentCustomers);

    if (penalty < minPenalty) {
      minPenalty = penalty;
      bestClosingHour = hour;
    }

    // Update current customers count
    if (hour < n && customers[hour] === "Y") {
      currentCustomers++;
    }
  }

  return bestClosingHour; // Return the hour with the minimum penalty
};

/*
Explanation of the Approach:
The idea behind this solution is to iterate through each hour as a potential closing time and calculate the penalty for that closing time. To calculate the penalty, we count two things:

    The number of hours when the shop is open and no customers come.
    The number of hours when the shop is closed and customers come.

The total penalty is the sum of these two counts. We iterate through the hours, incrementing the counts accordingly, and keep track of the hour with the minimum penalty.
*/

/*
Complexity Analysis:
    The loop to calculate the total number of customers takes O(n) time.
    The main loop runs from 0 to n, where each iteration involves constant-time operations. However, within this loop, there is an additional step where we calculate the penalty, which is also based on the currentCustomers count. Since the maximum value of currentCustomers can be at most n, the calculation of penalty takes O(n) time for each iteration.

Considering these factors, the overall complexity is actually O(n^2).
*/
