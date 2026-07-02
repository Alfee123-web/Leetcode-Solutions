class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int st = 0;
        int maxl = 1;
        for (int i = 0; i < s.length(); i++) {
            int l = i;
            int h = i;
            //odd length pallindrome
            while (l >= 0 && h < s.length() &&s[l] == s[h]) {
                if (h - l + 1 > maxl) {
                    st = l;
                    maxl = h - l + 1;
                }

                l--;
                h++;
            }
            //even length pallindrome
             l = i;
            h = i + 1;
            while (l >= 0 && h < s.length() &&s[l] == s[h]) {
                if (h - l + 1 > maxl) {
                    st = l;
                    maxl = h - l + 1;
                }
                l--;
                h++;
            }
        }
        return s.substr(st, maxl);
    }
};