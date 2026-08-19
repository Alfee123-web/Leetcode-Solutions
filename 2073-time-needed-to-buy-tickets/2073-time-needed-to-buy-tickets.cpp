class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int target = tickets[k];
        int t = 0;
        for(int i = 0; i < n ; i ++){
            if(i <=k ){
                   t += min(tickets[i] , target);
            }else{
                t += min(tickets[i] , target-1);
            }
        }
        return t;
    }
};