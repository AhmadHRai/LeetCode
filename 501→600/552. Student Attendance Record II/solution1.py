""" 
4345ms Beats 44.39% of users with Python3
16.39MB Beats 100.00% of users with Python3
 """
class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 1000000007
        # Cache to store current sub-problem results.
        dp_curr_state = [[0] * 3 for _ in range(2)]
        # Cache to store next sub-problem results.
        dp_next_state = [[0] * 3 for _ in range(2)]

        # Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dp_curr_state[0][0] = 1

        # Iterate on smaller sub-problems and use the current smaller sub-problem 
        # to generate results for bigger sub-problems.
        for _ in range(n):
            for total_absences in range(2):
                for consecutive_lates in range(3):
                    # Store the count when 'P' is chosen.
                    dp_next_state[total_absences][0] = (
                        dp_next_state[total_absences][0] + 
                        dp_curr_state[total_absences][consecutive_lates]
                    ) % MOD
                    # Store the count when 'A' is chosen.
                    if total_absences < 1:
                        dp_next_state[total_absences + 1][0] = (
                            dp_next_state[total_absences + 1][0] + 
                            dp_curr_state[total_absences][consecutive_lates]
                        ) % MOD
                    # Store the count when 'L' is chosen.
                    if consecutive_lates < 2:
                        dp_next_state[total_absences][consecutive_lates + 1] = (
                            dp_next_state[total_absences][consecutive_lates + 1] + 
                            dp_curr_state[total_absences][consecutive_lates]
                        ) % MOD

            # Next state sub-problems will become current state sub-problems in the next iteration.
            dp_curr_state = [row[:] for row in dp_next_state]
            # Next state sub-problem results will reset to zero.
            dp_next_state = [[0] * 3 for _ in range(2)]

        # Sum up the counts for all combinations of length 'n' with different absent and late counts.
        count = sum(dp_curr_state[total_absences][consecutive_lates] \
                    for total_absences in range(2) \
                    for consecutive_lates in range(3)) % MOD
        return count

""" 
Approach:
The solution uses dynamic programming to count all possible attendance records with n days,
considering the constraints of at most one 'A' (absence) and at most two consecutive 'L's (lates).
It iterates through smaller sub-problems to generate results for larger sub-problems, storing the 
counts of different attendance records based on the choices of 'P' (present), 'A' (absent), or 'L' (late).
The final count is the sum of all possible attendance records with the given constraints.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of days. The solution iterates through 'n' days and 
  performs constant-time operations for each day.
- Space Complexity: O(1). The solution uses constant space for storing the current and next state 
  sub-problem results, regardless of the value of 'n'.
"""