impl Solution
{
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32
    {
        let n: usize = nums.len() as usize;

        if (n < 3)
        {
            return 0;
        }
        else
        {
            // Sort array
            let mut arr: Vec<i32> = nums;
            arr.sort();

            let mut result: i32 = arr[0] + arr[1] + arr[2];

            for i in 0..n
            {
                let mut left:  usize = i + 1;
                let mut right: usize = n - 1;

                while (left < right)
                {
                    let sum: i32 = arr[i] + arr[left] + arr[right];

                    let currentDifference = (sum - target).abs();
                    let closestDifference = (result - target).abs();

                    if (currentDifference < closestDifference)
                    {
                        result = sum;
                    }

                    // Update pointers
                    if (sum < target)
                    {
                        left += 1;
                    }
                    else if (sum > target)
                    {
                        right -= 1;
                    }
                    else
                    {
                        return target
                    }
                }
            }

            // Default return
            return result;
        }
    }
}