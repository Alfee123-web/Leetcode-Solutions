class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //COUNT SORT
        int minV = -50000;
        int maxV = 50000;
        int range = maxV - minV + 1;
        vector<int>freq(range , 0);
        for(int num : nums){
                freq[num - minV]++;
        }
        int idx =0;
        for(int i = 0; i < range ; i++){
            while(freq[i] > 0){
                nums[idx++] = i + minV;
                freq[i]--;
            }
        }
        return nums;

    }
};