class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1; // 8
        int maxArea = 0;
        while (i < j) {
            int ht = min(height[i], height[j]);
            int area = ht * (j - i);
            maxArea = max(area, maxArea);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};