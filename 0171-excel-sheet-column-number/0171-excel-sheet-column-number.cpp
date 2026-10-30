class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;

        for(int i = 0 ; i < columnTitle.length() ; i++){
               int d = columnTitle[i] - 'A' + 1;
               ans = ans * 26 + d;
               //26 base => multiple
               //d new digit => add
        }
        return ans;
    }
};