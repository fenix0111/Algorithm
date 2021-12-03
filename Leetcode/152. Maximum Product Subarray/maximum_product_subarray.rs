impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut result: i32 = i32::MIN;
        let mut product: i32 = 1;
        for num in nums.iter() {
            if product == 0 {
                product = 1;
            }
            product *= *num;
            result = std::cmp::max(result, product);
        }
        
        product = 1;
        for num in nums.iter().rev() {
            if product == 0 {
                product = 1;
            }
            
            product *= *num;
            result = std::cmp::max(result, product);
        }
        
        return result;
    }
}
