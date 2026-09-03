class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(),piles.end());
        while(s<e){
            int m = s  +(e-s)/2;
            long long totH = 0;
            for(int pile : piles){
                totH += (pile + m -1)/m;
            }
            if(totH <= h){
                e = m;
            }else{
                s = m+1;
            }
        }
        return s;
    }
};