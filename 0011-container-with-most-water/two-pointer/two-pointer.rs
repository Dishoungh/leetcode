use std::cmp;

impl Solution
{
    pub fn max_area(height: Vec<i32>) -> i32
    {
        let n: usize = height.len() as usize;
        let mut max_area: i32 = 0;
        let mut left: usize = 0;
        let mut right: usize = n - 1;

        while (left < right)
        {
            // Area = width (right - left) * height (min(height[left], height[right]))
            let a: i32 = left as i32;
            let b: i32 = right as i32;
            let area = (b - a) * cmp::min(height[left], height[right]);

            // Update max_area
            max_area = cmp::max(area, max_area);
            
            // Update pointers
            if (height[left] < height[right])
            {
                left += 1;
            }
            else
            {
                right -= 1;
            } 
        }

        return max_area;
    }
}