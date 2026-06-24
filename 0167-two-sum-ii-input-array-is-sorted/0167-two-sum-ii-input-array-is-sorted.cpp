class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        const int offset = 1000;
        // shift upto 1000
        for(int i = 0; i< nums.size();i++){
            int comp = target - nums[i];
            if( comp <= 1000 && comp >= -1000 &&mp.find(comp + offset) != mp.end()){
                return {mp[comp + offset] + 1 , i+1};
            }
            mp[nums[i] + offset] = i;
        }
        return {};
    }
};