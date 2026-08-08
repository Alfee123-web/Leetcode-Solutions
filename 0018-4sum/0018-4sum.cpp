class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            //duplicacy skip
            for(int j = i +1 ; j < n; j ++){
                if(j > (i+1) && nums[j] == nums[j-1]) continue;
                  //duplicacy skip
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long s = nums[i];//overflow
                    s += nums[j];
                    s += nums[k];
                    s += nums[l];
                    if(s == target){
                        vector<int>temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                          //duplicacy skip
                    }else if(s < target) k++;
                    else l--;
                }

            }
        }

        return ans;
    }
};
//loop i , j 
// pointer k ,l