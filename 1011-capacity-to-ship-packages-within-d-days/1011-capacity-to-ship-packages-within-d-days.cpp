class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //same as koko eating banana
        int s = 0;
        int e =0;
        for(int w : weights){
            s = max(s,w);
            e += w;
        }
        int ans = e;
        while(s<=e){
            int m = s  + (e-s)/2;
            if(isPossible(weights,days,m)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
    private:
    bool isPossible(vector<int>&weights , int days , int capacity){
        int currDays = 1;
        int currLoad = 0;
        for(int w : weights){
            if(currLoad + w > capacity){
                currDays++;
                currLoad= w;
            }else{
                currLoad += w;
            }
        }
        return currDays <= days;
    }
};