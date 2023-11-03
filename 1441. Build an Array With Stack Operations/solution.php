class Solution {

function buildArray($target, $n) {
    $targetSet = array_flip($target);
    $result = [];

    for ($i = 1; $i <= end($target); $i++) {
        if (isset($targetSet[$i])) {
            $result[] = "Push";
        } else {
            $result[] = "Push";
            $result[] = "Pop";
        }
    }
    return $result;
}

}

<!-- 
    Approach

    Set Conversion: Convert the target list to a set. This conversion allows us to check the existence of a number in the target list in constant time, O(1).
    Iterative Process: Iterate through the numbers from 1 up to the last element of the target list.
        If the current number is in the target set, we only "Push".
        If the current number is not in the target set, we "Push" and then "Pop" immediately, indicating that the number is not required in the final stack.
    Completion: Once we've reached the last number in the target list, we can be sure that we've constructed the target list in the stack and stop our operations.

Complexity

    Time complexity: O(n). The iteration goes up to the last element of the target list, which could be as large as nnn. Each operation (push/pop) is O(1).
    Space complexity: O(1). While the result list can grow up to the size of the target list, we're only using a constant amount of extra space in our solution (ignoring the space required for the output list).

 -->