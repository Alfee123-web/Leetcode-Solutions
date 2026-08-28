class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){//even
            swap(nums[i] , nums[k]);
            k++;
            }
        }
        return nums;
    }
};