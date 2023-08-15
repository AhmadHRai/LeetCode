class Solution {
    function getWinner($arr, $k) {
        if ($k == 1) {
            return max($arr[0], $arr[1]);
        }
        if ($k >= count($arr)) {
            return max($arr);
        }

        $current_winner = $arr[0];
        $consecutive_wins = 0;

        for ($i = 1; $i < count($arr); $i++) {
            if ($current_winner > $arr[$i]) {
                $consecutive_wins++;
            } else {
                $current_winner = $arr[$i];
                $consecutive_wins = 1;
            }

            if ($consecutive_wins == $k) {
                return $current_winner;
            }
        }

        return $current_winner;
    }
}