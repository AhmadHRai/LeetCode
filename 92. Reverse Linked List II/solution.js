/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function (head, left, right) {
  if (!head || left === right) {
    return head;
  }

  // Create a dummy node to handle edge cases.
  const dummy = new ListNode(-1);
  dummy.next = head;
  let prev = dummy;

  // Traverse to the node just before "left".
  for (let i = 1; i < left; i++) {
    prev = prev.next;
  }

  // Initialize pointers for reversing the sublist.
  let curr = prev.next;
  let next = null;
  let reversed = null;

  // Reverse nodes from "left" to "right".
  for (let i = left; i <= right; i++) {
    next = curr.next;
    curr.next = reversed;
    reversed = curr;
    curr = next;
  }

  // Connect the reversed sublist back to the original list.
  prev.next.next = curr;
  prev.next = reversed;

  return dummy.next;
};

/* 
Time Complexity:
    We traverse the list once to reach the node just before "left" (O(left)).
    Then, we reverse the sublist from "left" to "right" (O(right - left + 1)).
    Overall, the time complexity is O(left + right - left + 1) = O(right).

Space Complexity:
    We use a few extra pointers, but they do not depend on the size of the input list.
    Therefore, the space complexity is O(1).

Key Notes/Gotchas:
    Be careful with index and pointer manipulation while reversing the sublist.
    The dummy node simplifies the edge cases when "left" is at the beginning of the list.
*/
