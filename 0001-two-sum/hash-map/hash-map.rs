impl Solution
{
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32>
    {
        let mut hashMap = std::collections::HashMap::new();

        for (value, key) in nums.iter().enumerate()
        {
            let required = target - key;

            if let Some(&foundIdx) = hashMap.get(&required)
            {
                return vec![foundIdx as i32, value as i32];
            }
            else
            {
                hashMap.insert(key, value);
            }
        }  

        // No valid solution found
        vec![]
    }
}