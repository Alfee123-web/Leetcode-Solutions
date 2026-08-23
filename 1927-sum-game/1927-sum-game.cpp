class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int half = n/2;
        int diff = 0;
        for(int i = 0; i < n ; i++){
            int val = (num[i] == '?') ? 9 : (num[i]-'0') * 2;
            diff += (i < half) ? val : -val;
        }
        return diff != 0;
    }
};