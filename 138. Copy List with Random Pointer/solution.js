/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function (head) {
  if (!head) return null;

  // Step 1: Create a mapping of original nodes to their new nodes.
  const mapping = new Map();
  let current = head;
  while (current) {
    mapping.set(current, new Node(current.val));
    current = current.next;
  }

  // Step 2: Update the next and random pointers for the new nodes.
  current = head;
  while (current) {
    const newNode = mapping.get(current);
    newNode.next = mapping.get(current.next) || null;
    newNode.random = mapping.get(current.random) || null;
    current = current.next;
  }

  // The head of the copied list is the new node corresponding to the original head.
  return mapping.get(head);
};

/**
The time complexity of this code is O(n), where n is the number of nodes in the linked list.
    In the first while loop, you iterate through all the nodes of the original linked list once to create a mapping of original nodes to their new nodes. This loop has a time complexity of O(n).
    In the second while loop, you again iterate through all the nodes of the original linked list once to update the next and random pointers for the new nodes. This loop also has a time complexity of O(n).
Overall, the code has a linear time complexity because the two loops are not nested.

The space complexity of this code is O(n), where n is the number of nodes in the linked list.
    The mapping object (a Map) stores a mapping of original nodes to their new nodes, and in the worst case, it can have n entries (one entry for each node). Therefore, the space complexity for the mapping object is O(n).
    Apart from the mapping object, there is a constant amount of additional space used for variables and temporary data structures, which does not depend on the input size and can be considered O(1).
So, the overall space complexity is dominated by the mapping object, making it O(n).
 */
