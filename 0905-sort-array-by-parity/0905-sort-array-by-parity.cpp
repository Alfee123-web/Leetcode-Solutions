class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int c = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i]%2 == 0){
                swap(nums[c] , nums[i]);//2 1 3 4
                  c++;//1
            }
           
        }
        return nums;
    }
};