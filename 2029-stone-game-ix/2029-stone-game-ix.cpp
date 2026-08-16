class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>freq(3,0);
        for(int stone :stones){
            freq[stone % 3]++;
        }
        if(freq[0] % 2 == 0){
            return freq[1] > 0 && freq[2] > 0;
        }else{
            return abs(freq[1] - freq[2]) > 2;
        }
    }
};