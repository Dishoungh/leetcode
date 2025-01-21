impl Solution
{
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>>
    {
        let n: usize = nums.len() as usize;

        // Sort array
        let mut arr: Vec<i32> = nums;
        arr.sort();

        // Initialize return vector
        let mut result: Vec<Vec<i32>> = Vec::new();

        if (n >= 4)
        {
            for i in 0..(n-3)
            {
                // Skip duplicates
                if ((i > 0) && (arr[i] == arr[i - 1]))
                {
                    continue;
                }
                else
                {
                    for j in (i+1)..(n-2)
                    {
                        if ((j > (i + 1)) && (arr[j] == arr[j - 1]))
                        {
                            continue;
                        }
                        else
                        {
                            // Create two pointers
                            let mut k: usize = (j + 1);
                            let mut l: usize = (n - 1);

                            while (k < l)
                            {
                                // Calculate sum
                                let sum: i64 = (arr[i] as i64) + (arr[j] as i64) + (arr[k] as i64) + (arr[l] as i64);

                                if (sum < (target as i64))
                                {
                                    k += 1;
                                }
                                else if (sum > (target as i64))
                                {
                                    l -= 1;                                
                                }
                                else
                                {
                                    // Add quadtriplet
                                    result.push(vec![arr[i], arr[j], arr[k], arr[l]]);

                                    k += 1;
                                    l -= 1;

                                    // Skip duplicates
                                    while ((k < l) && (arr[k] == arr[k - 1]))
                                    {
                                        k += 1;
                                    }

                                    //Skip duplicates for 4th number
                                    while ((k < l) && (arr[l] == arr[l + 1]))
                                    {
                                        l -= 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }   
        }

        return result;
    }
}