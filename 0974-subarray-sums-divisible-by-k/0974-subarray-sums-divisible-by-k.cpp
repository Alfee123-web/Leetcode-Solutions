class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>ans(k , 0);
        ans[0] = 1;
        int s = 0;
         int res = 0;
        for(int i = 0; i < nums.size(); i++){
            s += nums[i];
            int r = s % k;
            if(r < 0){
                r = r + k;
            }
            res += ans[r];
            ans[r]++;
        }
        return res;
    }
};