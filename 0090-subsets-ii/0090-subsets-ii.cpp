class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back({});
        int s = 0;
        int e =0;
        for(int i = 0; i < nums.size();i++){
            s = 0;
            if(i > 0 && nums[i] == nums[i-1]){
                s = e;
            }
            e = ans.size();

        for(int j = s;j < e; j++){
             vector<int>copy = ans[j];
             copy.push_back(nums[i]);
             ans.push_back(copy);
        }
    }
    return ans;
    }
};