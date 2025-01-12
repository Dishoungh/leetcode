public class Solution
{
    public int MaxArea(int[] height)
    {
        int n = height.Length;
        int max_area = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int area = (j - i) * Math.Min(height[i], height[j]); // Area = width * height
                max_area = Math.Max(area, max_area);
            }
        }

        return max_area;
    }
}