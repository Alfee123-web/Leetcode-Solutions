class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int p = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for(int i = 1; i < nums.size();i++){
            int currn = nums[i];
            if(currn < 0){
                swap(currMax , currMin);
            }
            currMax = max(currn, currMax * currn);
            currMin = min(currn, currMin * currn);
            p = max(p , currMax);
        }
        return p;
    }
};