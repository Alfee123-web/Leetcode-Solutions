class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxN = 0;
        vector<bool> ans(n);

        for (int i = 0; i < n; i++) {
             maxN = max(candies[i],maxN);
           
              }

        for (int i = 0; i < n; i++) {
            if (candies[i] + extraCandies >= maxN) {
                ans[i] = 1;
            }else{
                ans[i] = 0;
            }

        }
        return ans;
    }
};