// The function takes two parameters: head, which is the head of the linked list,
// and prev, which is the previous node in the reversed list, initialized to null.
var reverseList = (head, prev = null) => {
  // Use a while loop to iterate through the linked list until the head is null,
  // indicating the end of the list.
  while (head) {
    // Use destructuring assignment to swap the next pointers of the current node
    // and the previous node. This effectively reverses the direction of the link.
    // The expression [head.next, prev, head] = [prev, head, head.next] does the following:
    // - head.next is assigned to prev, making the current node point to the previous node.
    // - prev is assigned to head, updating the previous node to the current node.
    // - head.next is assigned to head, moving the head pointer to the next node in the original list.
    [head.next, prev, head] = [prev, head, head.next];
  }
  // Return the new head of the reversed list, which is the last node of the original list.
  return prev;
};

/* 
Approach:
    The approach used here is an iterative method to reverse a linked list. It involves three pointers: head to traverse the list, nextNode to keep track of the next node in the 
    original list, and prevNode to keep track of the previous node in the reversed list. The algorithm iterates through the list, reversing the next pointer of each node to point to 
    the previous node, and updating the prevNode and head pointers accordingly.

Complexity:
    Time Complexity: The time complexity of this algorithm is O(N), where N is the number of nodes in the list. This is because each node in the list is visited exactly once during the iteration.

    Space Complexity: The space complexity is O(1), which means the space required does not grow with the size of the input list. This is because only a fixed number of pointers (nextNode and prevNode) are used, and their space requirements do not depend on the size of the list.
 */
