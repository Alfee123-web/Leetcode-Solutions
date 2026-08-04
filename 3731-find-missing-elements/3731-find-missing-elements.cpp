class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
         int n = nums.size();
         vector<int>ans;
        unordered_set<int>s;
       int minV = INT_MAX;
       int maxV = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
            minV = min(nums[i] , minV);
            maxV = max(nums[i] , maxV);
        }
      for(int i = minV + 1 ; i < maxV ;i++){
            if(s.count(i) == 0){
                ans.push_back(i);
            }
      }
     return ans;
        
    }
};