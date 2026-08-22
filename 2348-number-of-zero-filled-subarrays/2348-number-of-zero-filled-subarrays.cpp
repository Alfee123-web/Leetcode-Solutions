class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarray = 0;//streak
        long long occ = 0;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            if(nums[i] == 0){
                subarray++;
               occ += subarray;
        }else{
        subarray = 0;
        }
        }
        return occ;
    }
};