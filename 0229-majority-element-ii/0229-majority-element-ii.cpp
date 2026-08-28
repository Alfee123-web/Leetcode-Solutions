class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
         vector<int>ans;
        unordered_map<int ,int>freq;

        for(int num : nums){
              freq[num]++;//1 2
        }
       for(auto const& [key,count]:freq){
        if(count > n/3){
               ans.push_back(key);
        }
       }
        return ans;
    }
};