class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size();i++){
            int seen = target - nums[i];
            if(mp.find(seen) != mp.end()){
                return {mp[seen],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};