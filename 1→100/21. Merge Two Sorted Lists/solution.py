# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Check for empty lists
        if not list1:
            return list2
        if not list2:
            return list1

        # Set the head of the merged list
        if list1.val <= list2.val:
            merged_head = list1
            list1 = list1.next
        else:
            merged_head = list2
            list2 = list2.next

        # Pointer for the current node in the merged list
        current = merged_head

        # Merge the remaining nodes
        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next

        # Append any remaining nodes from list1 or list2
        current.next = list1 if list1 else list2

        return merged_head

"""

Explanation

The `mergeTwoLists` method merges two sorted singly-linked lists, `list1` and `list2`, into a single sorted linked list.

Approach:
- Check for empty lists: If either list is empty, return the other list.
- Set the head of the merged list (`merged_head`) to the smaller head between `list1` and `list2`.
- Use a `current` pointer to track the current node in the merged list.
- Traverse both lists simultaneously:
  - Compare the values of the current nodes of `list1` and `list2`.
  - Append the smaller node to the merged list and move the respective list's pointer forward.
- After exiting the loop, append any remaining nodes from `list1` or `list2` to the merged list.
- Return the head of the merged list.

Example:
If `list1 = 1 -> 3 -> 5` and `list2 = 2 -> 4 -> 6`:
- Start with `merged_head = 1`, since `list1.val <= list2.val`.
- After merging, the result is `1 -> 2 -> 3 -> 4 -> 5 -> 6`.

Complexity:

Time Complexity:
- O(m + n), where m and n are the lengths of `list1` and `list2` respectively. This is because we traverse both lists once.

Space Complexity:
- O(1), as we use only a constant amount of extra space (variables `merged_head`, `current`, and temporary pointers).

"""

