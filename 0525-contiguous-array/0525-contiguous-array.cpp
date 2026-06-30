class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxl =0;
        int s = 0;
        unordered_map<int,int>mp;
             mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                s -= 1;
            }else{
                s+=1;
            }
          
                if(mp.find(s) != mp.end()){
                    maxl = max(maxl , i - mp[s]);
                }else{
                    mp[s] = i;
                }
            }
        return maxl;
    }
};