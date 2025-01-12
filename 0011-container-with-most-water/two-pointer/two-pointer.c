int maxArea(int* height, int heightSize)
{
    int max_area = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right)
    {
        // Area = width (right - left) * height (min(height[left], height[right]))
        int area = (right - left) * ((height[left] < height[right]) ? height[left] : height[right]);

        // Update max_area
        max_area = (area > max_area) ? area : max_area;

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