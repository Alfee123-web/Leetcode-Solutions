class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_set<char>set;
                for (int k = i; k <= j; k++) {
                    set.insert(s[k]);
                }
                bool isNice = true;
                for (char c : set) {
                    if (set.find(toupper(c)) == set.end() ||
                        set.find(tolower(c)) == set.end()) {
                        isNice = false;
                        break;
                    }
                }
                if (isNice) {
                    int l = j - i + 1;
                    if (l > ans.length()) {
                        ans = s.substr(i, l);
                    }
                }
            }
        }
        return ans;
    }
};