class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s =0;
        int e = n-1;//3
        while(s< e){
            int m = s  +(e-s)/2;//1=>13
            if(nums[m] > nums[e]){
                //decrease
                s = m +1;
                }else{
                    e = m;
                }
        }
        return nums[s];
    }
};