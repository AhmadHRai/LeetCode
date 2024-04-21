/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode[]}
 */
var splitListToParts = function (head, k) {
  // Step 1: Calculate the length of the linked list.
  let length = 0;
  let currentNode = head;
  while (currentNode !== null) {
    length++;
    currentNode = currentNode.next;
  }

  // Step 2: Calculate the size of each part and the number of parts with an extra node.
  const partSize = Math.floor(length / k); // Size of each part.
  let extraNodes = length % k; // Number of parts with an extra node.

  // Initialize an array to store the results (k parts).
  const result = [];

  // Step 3: Initialize a pointer to traverse the linked list.
  currentNode = head;

  // Step 4: Traverse the linked list and create k parts.
  for (let i = 0; i < k; i++) {
    let partHead = currentNode; // Head of the current part.

    // Calculate the size of the current part, considering extra nodes.
    const currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);

    // Traverse the current part.
    for (let j = 1; j < currentPartSize && currentNode !== null; j++) {
      currentNode = currentNode.next;
    }

    // Update the extraNodes count.
    if (extraNodes > 0) {
      extraNodes--;
    }

    if (currentNode !== null) {
      // Save the next node to cut off the current part.
      const nextNode = currentNode.next;
      currentNode.next = null;
      currentNode = nextNode;
    }

    // Add the current part to the result array.
    result.push(partHead);
  }

  // Step 5: If there are fewer nodes in the linked list than k, fill the remaining parts with null.
  while (result.length < k) {
    result.push(null);
  }

  return result;
};

// Time Complexity: O(N), where N is the number of nodes in the linked list.
// Space Complexity: O(K), where K is the number of parts.

/**
Additional Notes/Gotchas:
- Ensure that you handle cases where there are fewer nodes in the linked list than the given value of k by filling the remaining parts with null.
- The time complexity is O(N) because we traverse the entire linked list once to calculate its length and once to create k parts. The space complexity is O(K) for storing the result array.
 */
