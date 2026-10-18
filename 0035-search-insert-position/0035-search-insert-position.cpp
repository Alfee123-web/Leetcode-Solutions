class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;//0
        int e = nums.size();//4
        while(s < e){
            int m = s + (e-s)/2;//5
            if(nums[m] == target){
                return m;
            }else if(nums[m] > target){
                e = m;
            }else{
                s= m + 1;
            }
        }
        return s;
    }
};