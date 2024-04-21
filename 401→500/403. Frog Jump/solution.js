var canCross = function (stones) {
  const n = stones.length;

  // Create a map to store the possible jump distances at each stone
  const jumpMap = new Map();
  for (const stone of stones) {
    jumpMap.set(stone, new Set());
  }
  jumpMap.get(0).add(0); // The frog starts at the first stone with a jump of 0

  for (let i = 0; i < n; i++) {
    const stone = stones[i];
    for (const k of jumpMap.get(stone)) {
      for (let jump = k - 1; jump <= k + 1; jump++) {
        if (jump > 0 && jumpMap.has(stone + jump)) {
          jumpMap.get(stone + jump).add(jump);
        }
      }
    }
  }

  return jumpMap.get(stones[n - 1]).size > 0; // Check if the last stone is reachable
};

// Test cases
console.log(canCross([0, 1, 3, 5, 6, 8, 12, 17])); // Output: true
console.log(canCross([0, 1, 2, 3, 4, 8, 9, 11])); // Output: false
