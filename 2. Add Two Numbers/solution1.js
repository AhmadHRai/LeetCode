// Define a function that takes two singly-linked lists of non-negative integers and returns a singly-linked list that represents their sum
var addTwoNumbers = function (l1, l2) {
    // Create a dummy head node for the result list
    let head = new ListNode();
    // Create a pointer to the current node of the result list
    let curr = head;
    // Create a variable to store the carry over from the addition
    let rem = 0;

    // Loop until both lists are exhausted or there is no carry over
    while (l1 || l2 || rem) {
        // Get the values of the current nodes of the lists, or 0 if the list is null
        let l1Val = l1 ? l1.val : 0;
        let l2Val = l2 ? l2.val : 0;
        // Calculate the sum of the values and the carry over
        let sum = l1Val + l2Val + rem;
        // Update the carry over by dividing the sum by 10 and truncating the decimal part
        rem = ~~(sum / 10);

        // Move to the next nodes of the lists, or null if the list is null
        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
        // Create a new node with the value of the sum modulo 10 and append it to the result list
        curr.next = new ListNode(sum % 10);
        // Move to the next node of the result list
        curr = curr.next;
    }

    // Return the result list without the dummy head node
    return head.next;
};

/* The time complexity of this solution is O(max(m, n)), where m and n are the lengths of the input lists. This is because we use one loop to iterate through the lists, and each 
iteration takes O(1) time.

The space complexity of this solution is O(max(m, n)), because we use a new list to store the result, which has at most max(m, n) + 1 nodes in the worst case.
 */
