impl Solution
{
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32>
    {
        for i in 0..nums.len()
        {
            for j in 0..nums.len()
            {
                let sum:i32 = nums[i] + nums[j];

                if ((sum == target) && (i != j))
                {
                    return vec![i as i32, j as i32];
                }
            }
        } 

        // No valid solution found
        vec![]
    }
}