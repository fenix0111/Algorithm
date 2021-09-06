impl Solution {
    pub fn slowest_key(release_times: Vec<i32>, keys_pressed: String) -> char {
        let mut max_gap = release_times[0];
        let strs: Vec<char> = keys_pressed.chars().collect();
        let mut result = strs[0];
        
        let mut i = 1;
        while i < release_times.len() {
            let gap = release_times[i] - release_times[i - 1];
            if gap > max_gap {
                max_gap = gap;
                result = strs[i];
            } else if gap == max_gap {
                if strs[i] > result {
                    result = strs[i];
                }
            }
            i += 1;
        }
        
        return result;
    }
}
