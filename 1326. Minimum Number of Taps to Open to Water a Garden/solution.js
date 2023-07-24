/**
 * @param {number} n
 * @param {number[]} ranges
 * @return {number}
 */
var minTaps = function (n, ranges) {
  const intervals = [];

  // Create an array of intervals based on tap ranges
  for (let i = 0; i <= n; i++) {
    intervals.push([Math.max(0, i - ranges[i]), Math.min(n, i + ranges[i])]);
  }

  // Sort the intervals based on their start positions
  intervals.sort((a, b) => a[0] - b[0]);

  let taps = 0;
  let currentPosition = 0;
  let maxReach = 0;
  let i = 0;

  while (currentPosition < n) {
    while (i < intervals.length && intervals[i][0] <= currentPosition) {
      maxReach = Math.max(maxReach, intervals[i][1]);
      i++;
    }

    if (maxReach <= currentPosition) {
      return -1; // Unable to water the whole garden
    }

    taps++;
    currentPosition = maxReach;

    if (currentPosition >= n) {
      return taps;
    }
  }

  return taps;
};

// Test cases
console.log(minTaps(5, [3, 4, 1, 1, 0, 0])); // Output: 1
console.log(minTaps(3, [0, 0, 0, 0])); // Output: -1
