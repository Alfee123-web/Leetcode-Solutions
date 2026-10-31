class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s < e){
            int m = s  + (e-s)/2;//1 + 3 = 4 => 5
            if(nums[m] < nums[m+1]){
                 s = m +1;
            }else{
                e = m;
            }
        }
        return s;
    }
};