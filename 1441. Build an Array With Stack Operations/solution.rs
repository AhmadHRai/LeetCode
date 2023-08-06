impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let target_set: std::collections::HashSet<_> = target.iter().cloned().collect();
        let mut result = vec![];

        for i in 1..=*target.last().unwrap() {
            if target_set.contains(&i) {
                result.push("Push".to_string());
            } else {
                result.push("Push".to_string());
                result.push("Pop".to_string());
            }
        }
        result
    }
}