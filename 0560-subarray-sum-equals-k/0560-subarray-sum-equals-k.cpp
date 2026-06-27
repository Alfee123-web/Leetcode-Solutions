class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int  c = 0;
        int s = 0;
        mp[0] =1;
        for(int i = 0 ;i < nums.size(); i++){
            s += nums[i];
            if(mp.find(s-k) != mp.end()){
                c += mp[s-k];
            }
   mp[s]++;
        }
  return c;
    }
};