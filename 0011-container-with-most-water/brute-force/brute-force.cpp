using namespace std;
class Solution
{
    public:
        int maxArea(vector<int>& height)
        {
            int n = height.size();
            int max_area = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int area = (j - i) * min(height[i], height[j]); // Area = width * height
                    max_area = max(area, max_area);
                }
            }

            return max_area;
        }
};