class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
             totalSum += nums[i]; // 28
        }
        // for (int i = 1; i < nums.size(); i++) {
        //     leftSum = nums[i-1] ;//1
        // }
        for (int i = 0; i < nums.size(); i++) {
                 int rightSum = totalSum - leftSum - nums[i];
            if (rightSum == leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};