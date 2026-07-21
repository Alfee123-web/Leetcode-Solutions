class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxV = 0;
        for(int i = 0; i < candies.size(); i++){
           
            maxV = max(candies[i] , maxV);
        }
        vector<bool>res;
        for(int i = 0 ;i < candies.size(); i++){
        
                res.push_back(candies[i] + extraCandies >= maxV);
            }
        
        return res;     
    }
};