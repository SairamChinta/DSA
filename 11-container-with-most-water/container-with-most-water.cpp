class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            // Calculate the width and the height (the shorter line limits water level)
            int width = right - left;
            int minHeight = min(height[left], height[right]);

            // Calculate area and update max
            int area = width * minHeight;
            maxWater = max(maxWater, area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
