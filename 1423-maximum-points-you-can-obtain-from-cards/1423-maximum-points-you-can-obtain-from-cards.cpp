class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftS = 0 ; int rightS = 0; int maxS =0;
        for(int i = 0; i <= k-1; i++){
            leftS = leftS + cardPoints[i];
            maxS = leftS;
        }
        int rightidx = n-1;
        for(int i = k-1;i >=0 ; i--){
            leftS = leftS - cardPoints[i];
            rightS = rightS + cardPoints[rightidx];
            rightidx = rightidx-1;
            maxS = max(maxS , leftS + rightS);
        }
        return maxS;
    }
};