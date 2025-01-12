using namespace std;
class Solution
{
    public:
        int maxArea(vector<int>& height)
        {
            int n = height.size();
            int max_area = 0;
            int left = 0;
            int right = n - 1;

            while (left < right)
            {
                // Area = width (right - left) * height (min(height[left], height[right]))
                int area = (right - left) * min(height[left], height[right]);

                // Update max_area
                max_area = max(area, max_area);
                
                // Update pointers
                if (height[left] < height[right])
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }

            return max_area;
        }
};