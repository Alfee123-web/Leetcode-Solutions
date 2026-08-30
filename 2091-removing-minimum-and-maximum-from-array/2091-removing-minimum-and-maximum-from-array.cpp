class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1 ) return 1;
        int minI = 0;
        int maxI = 0;
        for(int i = 0; i< n ; i++){
            if(nums[i] < nums[minI]){
                minI = i;
            }
            if(nums[i] > nums[maxI]){
                maxI= i;
            }
        }
        int s = min(minI,maxI);
        int e = max(minI , maxI);
        int delF = e+1;
        int delB = n-s;
        int both = (s+1) + (n-e);
        return min({delF , delB , both});

    }
};