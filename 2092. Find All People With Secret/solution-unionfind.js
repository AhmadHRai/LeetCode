// Define the function to find all people who know the secret.
const findAllPeople = function (n, meetings, firstPerson) {
  // Sort meetings by time.
  meetings.sort((a, b) => a[2] - b[2]);

  // Initialize a Union-Find data structure with n elements.
  const uf = new UnionFind(n);

  // Connect the first person (0) and the first person in the input.
  uf.connect(0, firstPerson);

  // Initialize an array to hold people involved in the current meeting time.
  let ppl = [];

  // Iterate through the sorted meetings.
  for (let i = 0, len = meetings.length; i < len; ) {
    ppl = []; // Reset the array for the current meeting time.
    const time = meetings[i][2]; // Current meeting time.

    // Group all meetings at the same time.
    while (i < len && meetings[i][2] === time) {
      // Connect the two people in the meeting.
      uf.connect(meetings[i][0], meetings[i][1]);
      // Add the people to the current meeting group.
      ppl.push(meetings[i][0]);
      ppl.push(meetings[i][1]);
      i++; // Move to the next meeting.
    }

    // Reset the union-find connections for people not connected to the first person.
    for (const n of ppl) {
      if (!uf.connected(0, n)) uf.reset(n);
    }
  }

  // Collect all people connected to the first person (0).
  const ans = [];
  for (let i = 0; i < n; ++i) {
    if (uf.connected(0, i)) ans.push(i);
  }

  // Return the list of people who know the secret.
  return ans;
};

// Define the Union-Find class.
class UnionFind {
  constructor(n) {
    // Initialize the array with each element being its own parent.
    this.arr = Array(n)
      .fill(null)
      .map((_, i) => i);
  }

  // Connect two elements in the union-find structure.
  connect(a, b) {
    this.arr[this.find(a)] = this.find(this.arr[b]);
  }

  // Find the root of an element.
  find(a) {
    return this.arr[a] === a ? a : (this.arr[a] = this.find(this.arr[a]));
  }

  // Check if two elements are connected.
  connected(a, b) {
    return this.find(a) === this.find(b);
  }

  // Reset the union-find structure for an element.
  reset(a) {
    this.arr[a] = a;
  }
}

/* 
Approach

    Sort Meetings: The meetings are sorted by their time to process them in chronological order.
    Union-Find Initialization: A Union-Find data structure is initialized with n elements, where n is the total number of people.
    Connect People: For each meeting, the two people involved are connected in the Union-Find structure.
    Group by Time: Meetings are grouped by their time, and within each group, connections are made between all people involved.
    Reset Connections: For each group, if a person is not connected to the first person (0), their connections are reset. This ensures that only people who have met at the same time as the first person are considered to know the secret.
    Collect People: Finally, all people connected to the first person (0) are collected and returned as the result.

Complexity Analysis

    Time Complexity: The time complexity is primarily influenced by the sorting of meetings (O(n log n)) and the Union-Find operations (O(n) for each person in the worst case). However, since the Union-Find operations are amortized over many operations, the actual time complexity is closer to O(n).
    Space Complexity: The space complexity is O(n) due to the storage required for the Union-Find structure and the array to hold the people involved in each meeting.


Why Union Find Performs Better

  The Union-Find data structure is highly efficient for solving problems related to connectivity, such as determining if two elements are connected or connecting two elements. By using 
  Union-Find, this solution can efficiently manage connections between people based on their meetings, which is crucial for identifying who knows the secret.

  The sorting of meetings by time is a key optimization that allows the algorithm to process meetings in chronological order, ensuring that connections are made in the correct order. 
  This approach, combined with the efficient Union-Find operations, results in a solution that is both space- and time-efficient for the problem at hand.
*/
