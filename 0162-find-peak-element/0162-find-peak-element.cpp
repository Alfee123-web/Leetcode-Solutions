class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1; // 6
        while (s < e) {
            int m = s + (e - s) / 2; // 3=>3
            if (nums[m] < nums[m + 1]) {
                s = m + 1;
            } else {
                e = m ;
            }
        }
        return s;
    }
};