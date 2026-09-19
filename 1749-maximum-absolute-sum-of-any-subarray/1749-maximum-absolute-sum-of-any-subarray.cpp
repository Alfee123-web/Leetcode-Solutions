class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int minS = nums[0];
        int maxS = nums[0];
        for(int i = 1; i< nums.size();i++){
            currMax = max(nums[i], nums[i] + currMax);
            maxS = max(maxS , currMax);

            currMin = min(nums[i] , nums[i] + currMin);
            minS = min(minS , currMin);

        }
        return max(maxS, abs(minS));

    }
};