class Solution {
    const long long LIMIT = 1000001;
    long long countWays(vector<int>& cnt, int total) {
        long long res = 1;
        int rem = total;
        for (int i = 0; i < 26; i++) {
            int c = cnt[i];
            for (int j = 1; j <= c; j++) {
                res = res * (rem - c + j) / j;
                if (res > LIMIT)
                    return LIMIT;
            }
            rem -= c;
        }
        return min(res, LIMIT);
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        vector<int> half(26, 0);
        int half_len = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            half_len += half[i];
            if (freq[i] % 2 == 1) {
                mid = 'a' + i;
            }
        }
        if (countWays(half, half_len) < k)
            return "";
        string left = "";
        for (int pos = 0; pos < half_len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0)
                    continue;
                half[ch]--;
                long long ways = countWays(half, half_len - pos - 1);
                if (ways >= k) {
                    left += (char)('a' + ch);
                    break;
                } else {
                    k -= ways;
                    half[ch]++;
                }
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (mid != 0) {
            return left + mid + right;
        }
        return left + right;
    }
};