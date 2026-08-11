class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];//1
        int idx = 1;
        //sequential 
        for(int i = 1; i< n ; i++){
            if(nums[i] == nums[i-1]+1){
               sum += nums[i];//12
            }else {
                  break;
            } 
        }
        while(find(nums.begin(),nums.end(),sum) != nums.end()){
            sum++;
        }
          
        return sum;
    }
};