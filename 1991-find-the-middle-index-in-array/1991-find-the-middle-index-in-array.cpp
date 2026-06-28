class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftS = 0;
        int totS = 0;
        for(int i = 0; i < nums.size(); i++){
           totS += nums[i];//16
        }
        for(int i = 0; i < nums.size(); i++){
           int rightS = totS - leftS - nums[i];
           if(leftS == rightS){
            return i;
           }else{
            leftS += nums[i];
           }
        }
        return -1;
    }
};