use std::cmp;

impl Solution
{
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64
    {
        let s1: i32 = nums1.len() as i32;
        let s2: i32 = nums2.len() as i32;

        if (s1 > s2)
        {
            // Swap arrays
            return Self::find_median_sorted_arrays(nums2, nums1);
        }
        else
        {
            // Calculate left and right pointers
            let mut left: i32  = 0;
            let mut right: i32 = s1;

            while (left <= right)
            {
                // Calculate partitions
                let p1: i32 = (left + right) >> 1;
                let p2: i32 = ((s1 + s2 + 1) >> 1) - p1;
                
                let mut l1: i32 = std::i32::MIN;
                let mut l2: i32 = std::i32::MIN;
                let mut r1: i32 = std::i32::MAX;
                let mut r2: i32 = std::i32::MAX;

                if (p1 != 0)
                {
                    let idx: usize = p1 as usize;
                    l1 = nums1[idx - 1];
                }

                if (p2 != 0)
                {
                    let idx: usize = p2 as usize;
                    l2 = nums2[idx - 1];
                }

                if (p1 != s1)
                {
                    let idx: usize = p1 as usize;
                    r1 = nums1[idx];
                }

                if (p2 != s2)
                {
                    let idx: usize = p2 as usize;
                    r2 = nums2[idx];
                }

                if ((l1 <= r2) && (l2 <= r1))
                {
                    let total: i32 = s1 + s2;

                    if ((total % 2) != 0)
                    {
                        let result: f64 = cmp::max(l1, l2) as f64;
                        return result;
                    }
                    else
                    {
                        let tmp: i32 = cmp::max(l1, l2) + cmp::min(r1, r2);
                        let ftmp: f64 = tmp as f64;
                        let result: f64 =  ftmp / 2.0;
                        return result;
                    }
                }
                else if (l1 > r2)
                {
                    right = p1 - 1;
                }
                else
                {
                    left = p1 + 1;
                }
            }
        }

        return 0.0;
    }
}