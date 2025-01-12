int maxArea(int* height, int heightSize)
{
    int max_area = 0;

    for (int i = 0; i < heightSize; i++)
    {
        for (int j = 0; j < heightSize; j++)
        {
            int area = (j - i) * ((height[i] <= height[j]) ? height[i] : height[j]); // Area = width * height
            max_area = (area > max_area) ? area : max_area;
        }
    }

    return max_area;
}