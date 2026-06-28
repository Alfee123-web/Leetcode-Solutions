class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> ans(k , 0);
          ans[0] = 1;
          int sum = 0;
          int res =0;
          for(int i = 0; i <nums.size(); i++){
            sum += nums[i];
             int rem = sum % k;
             if(rem < 0){
                rem = rem + k;
             }
             res += ans[rem];
             ans[rem]++;
          }
          return res;
    }
};
