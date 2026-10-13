class Solution {
public:
    int findMin(vector<int>& nums) {
        int minV = nums[0];
        for(int i = 0 ;i < nums.size(); i++){
            minV = min(nums[i] , minV);
        }
        return minV;
    }
};