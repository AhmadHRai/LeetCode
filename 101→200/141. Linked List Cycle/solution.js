/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
  if (!head || !head.next) {
    return false; // There can be no cycle with 0 or 1 nodes
  }

  let slow = head;
  let fast = head.next;

  while (slow !== fast) {
    if (!fast || !fast.next) {
      return false; // If there's no cycle, fast will reach the end
    }
    slow = slow.next;
    fast = fast.next.next;
  }

  return true; // If slow and fast meet, there's a cycle
};

/**
Time Complexity:
    The slow pointer moves one step at a time.
    The fast pointer moves two steps at a time.
    In the worst case, when there is no cycle, both pointers will traverse the entire linked list.
    Therefore, the time complexity is O(N), where N is the number of nodes in the linked list.

Space Complexity:
    The space complexity is O(1) because it uses only two pointers (slow and fast) and a constant amount of extra space regardless of the size of the linked list.
    The algorithm does not use any data structures whose space consumption depends on the size of the input.
 */
