// Function that takes an array of paths and returns the destination city
const destCity = function (paths) {
  // Create a hash map from the paths array, where the key is the origin city and the value is the destination city
  const hash = new Map(paths);

  // Loop through the values of the hash map, which are the destination cities
  for (const to of hash.values()) {
    // Check if the current destination city is not a key in the hash map, meaning it is not an origin city
    if (!hash.has(to))
      // If so, return the current destination city as the final answer
      return to;
  }
};

// Time complexity: O(n), where n is the number of paths in the input array
// Space complexity: O(n), where n is the number of paths in the input array
