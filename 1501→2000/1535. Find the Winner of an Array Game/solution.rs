impl Solution {
    pub fn get_winner(arr: Vec<i32>, k: i32) -> i32 {
        if k == 1 {
            return arr[0].max(arr[1]);
        }
        if k as usize >= arr.len() {
            return *arr.iter().max().unwrap();
        }

        let mut current_winner = arr[0];
        let mut consecutive_wins = 0;

        for &num in &arr[1..] {
            if current_winner > num {
                consecutive_wins += 1;
            } else {
                current_winner = num;
                consecutive_wins = 1;
            }

            if consecutive_wins == k {
                return current_winner;
            }
        }

        current_winner
    }
}

/* 
Approach

    Edge Cases: Check if kkk is 1 or if kkk is equal to or larger than the length of the array. These cases allow for immediate conclusions.
    Initialization: Initialize the current winner as the first element and set the consecutive wins count to zero.
    Iteration: Iterate through the array starting from the second element. For each element:
        If the current winner is greater, increment the consecutive win count.
        If the current element is greater, it becomes the new winner and the consecutive win count resets to 1.
        If at any point the consecutive win count reaches kkk, the current winner is the answer.
    Final Winner: If the loop completes without finding an answer, the current winner after the loop is the answer.

This approach ensures that we only iterate through the list once, making the solution efficient.
Complexity

    Time complexity: O(n)
    The solution iterates through the array once. In the worst-case scenario, we examine all elements in the array. Hence, the time complexity is linear with respect to the size of the array.

    Space complexity: O(1)
*/