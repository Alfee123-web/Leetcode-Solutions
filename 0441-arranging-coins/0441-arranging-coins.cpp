class Solution {
public:
    int arrangeCoins(int n) {
          long long s = 1;
        long long e = n;
        long long ans = 0;
        while (s <= e) {
            long long m = s + (e - s) / 2;
            long long totalCoins = m * (m + 1) / 2;
            if (totalCoins <= n) {
                ans =m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return ans;
    }
};