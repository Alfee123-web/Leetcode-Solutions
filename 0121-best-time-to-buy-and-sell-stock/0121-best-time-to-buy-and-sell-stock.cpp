class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int bestBuy = prices[0];//first day price 

        int n = prices.size();
        for(int i = 0 ; i < n ; i++){
              if(prices[i] > bestBuy){
                maxP = max(maxP , prices[i]-bestBuy);
                // prices[i]-bestBuy => curr day profit
              }
              bestBuy = min(prices[i] , bestBuy);
        }
        return maxP;
    }
};