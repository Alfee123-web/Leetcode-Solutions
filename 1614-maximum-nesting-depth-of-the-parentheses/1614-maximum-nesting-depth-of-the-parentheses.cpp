class Solution {
public:
    int maxDepth(string s) {
        // stack<int>st;
        int currD = 0;
        int maxD = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                currD++; // 1 2 3
                 maxD = max(currD, maxD);
            } else if (s[i] == ')') {
                    currD--;
                }
            }
 return maxD;
    }
};