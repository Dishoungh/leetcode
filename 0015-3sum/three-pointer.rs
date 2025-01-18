impl Solution 
{
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>>
    {
        let n: usize = nums.len() as usize;

        // Sort array
        let mut arr: Vec<i32> = nums;
        arr.sort();

        // Initialize return vector
        let mut result: Vec<Vec<i32>> = Vec::new();

        for i in 0..(n-2)
        {
            // Skip duplicates
            if ((i > 0) && (arr[i] == arr[i - 1]))
            {
                continue;
            }
            else
            {
                let mut j: usize = (i + 1) as usize;
                let mut k: usize = (n - 1) as usize;

                while (j < k)
                {
                    let sum: i32 = arr[i] + arr[j] + arr[k];

                    if (sum == 0)
                    {
                        // Add triplet
                        let tmp: Vec<i32> = vec![arr[i], arr[j], arr[k]];
                        result.push(tmp);

                        k -= 1;

                        // Skip duplicates
                        while ((j < k) && (arr[k] == arr[k + 1]))
                        {
                            k -= 1;
                        }
                    }
                    else if (sum > 0)
                    {
                        k -= 1;
                    }
                    else
                    {
                        j += 1;
                    }
                }
            }
        }

        return result;
    }
}