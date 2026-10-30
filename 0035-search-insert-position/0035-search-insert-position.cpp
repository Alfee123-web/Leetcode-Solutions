class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();
        while(s < e){
            int m = s  +(e-s)/2;
            if(nums[m] == target){
                return m;
            }else if(nums[m] < target){
                s = m + 1;
            }else{
                e = m;
            }
        }
        return s;
    }
};