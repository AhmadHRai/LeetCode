// Define a function that takes two singly-linked lists of non-negative integers and returns a singly-linked list that represents their sum
var addTwoNumbers = function(l1, l2) {
    // Create a dummy head node for the result list
    var List = new ListNode(0);
    // Create a pointer to the current node of the result list
    var head = List;
    // Create a variable to store the sum of the values and the carry over from the addition
    var sum = 0;
    // Create a variable to store the carry over from the addition
    var carry = 0;

    // Loop until both lists are exhausted or there is a carry over
    while(l1!==null||l2!==null||sum>0){

        // If the first list is not null, add its value to the sum and move to the next node
        if(l1!==null){
            sum = sum + l1.val;
            l1 = l1.next;
        }
        // If the second list is not null, add its value to the sum and move to the next node
        if(l2!==null){
            sum = sum + l2.val;
            l2 = l2.next;
        }
        // If the sum is greater than or equal to 10, set the carry over to 1 and subtract 10 from the sum
        if(sum>=10){
            carry = 1;
            sum = sum - 10;
        }

        // Create a new node with the value of the sum and append it to the result list
        head.next = new ListNode(sum);
        // Move to the next node of the result list
        head = head.next;

        // Set the sum to the carry over and reset the carry over to 0
        sum = carry;
        carry = 0;

    }

    // Return the result list without the dummy head node
    return List.next;
};
/* The time complexity of this solution is O(max(m, n)), where m and n are the lengths of the input lists. This is because we use one loop to iterate through the lists, and each 
iteration takes O(1) time.

The space complexity of this solution is O(max(m, n)), because we use a new list to store the result, which has at most max(m, n) + 1 nodes in the worst case.
 */
