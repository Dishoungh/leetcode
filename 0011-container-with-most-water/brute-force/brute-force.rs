use std::cmp;

impl Solution
{
    pub fn max_area(height: Vec<i32>) -> i32
    {
        let n: usize = height.len() as usize;
        let mut max_area: i32 = 0;

        for i in 0..n
        {
            for j in 0..n
            {
                let a: i32 = i as i32;
                let b: i32 = j as i32;

                let area: i32 = (b - a) * cmp::min(height[i], height[j]); // Area = width * height
                max_area = cmp::max(area, max_area);
            }
        }

        return max_area;
    }
}