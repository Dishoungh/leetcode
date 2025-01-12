impl Solution
{
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64
    {
        let mut mergedVec: Vec<i32> = Vec::new();
        let mut median: f64 = 0.0;

        let mut i: usize = 0;
        let mut j: usize = 0;
        
        let m: usize = nums1.len() as usize;
        let n: usize = nums2.len() as usize;

        while ((i < m) && (j < n))
        {
            if (nums1[i] < nums2[j])
            {
                mergedVec.push(nums1[i]);
                i += 1;
            }
            else
            {
                mergedVec.push(nums2[j]);
                j += 1;
            }
        }

        while (i < m)
        {
            mergedVec.push(nums1[i]);
            i += 1;
        }

        while (j < n)
        {
            mergedVec.push(nums2[j]);
            j += 1;
        }

        let odd: u8 = ((nums1.len() + nums2.len()) % 2) as u8;

        if (odd == 0)
        {
            let idx1: usize = ((nums1.len() + nums2.len()) / 2) as usize;
            let idx2: usize = (((nums1.len() + nums2.len()) / 2) - 1) as usize;

            let a: i32 = mergedVec[idx1];
            let b: i32 = mergedVec[idx2];
            let tmp: f64 = (a + b) as f64;

            median = tmp / 2.0;
        }
        else
        {
            let idx: usize = ((nums1.len() + nums2.len()) / 2) as usize;
            median = mergedVec[idx] as f64;
        }

        return median
    }
}