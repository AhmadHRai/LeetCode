/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val === undefined ? 0 : val)
 *     this.next = (next === undefined ? null : next)
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
  // Base case: If the list is empty or has only one node, no swap needed.
  if (!head || !head.next) {
    return head;
  }

  // Store the second node (next node) to perform the swap
  const nextNode = head.next;

  // Recursively swap the rest of the pairs, starting from the third node.
  // After the recursive call, head will be the second node in the swapped pair.
  head.next = swapPairs(nextNode.next);

  // Now the second node's next should point to the current head node (the first node).
  nextNode.next = head;

  // Return the new head of the swapped pair, which is the second node
  return nextNode;
};

/**
 * Approach Summary:
 * - This is a recursive solution that swaps nodes in pairs in a singly linked list.
 * - If the list has fewer than two nodes, no swap is performed (base case).
 * - The first two nodes are swapped, and then the function is called recursively for the next pair of nodes.
 * - After the recursive call, we update the pointers to maintain the list structure.
 * - The key observation is that each pair swap reduces the problem size by 2 nodes, and the recursion progresses through the list.
 *
 * Time Complexity:
 * - The function visits each node exactly once, making the time complexity O(n), where n is the number of nodes in the linked list.
 *
 * Space Complexity:
 * - The space complexity is O(n) due to the recursive calls, which use the call stack. In the worst case, the depth of the recursion will be n/2 (for pairs of nodes), resulting in O(n) space usage for the call stack.
 */
