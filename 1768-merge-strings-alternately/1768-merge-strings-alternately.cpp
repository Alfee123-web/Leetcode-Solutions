class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = word1.size();
        int j = word2.size();
        int s1 = 0;
        int s2 = 0;
        string ans = "";
        while (s1 < i && s2 < j) {
            ans += word1[s1];
            ans += word2[s2];
            s1++;
            s2++;
        }
        while(s1 < i) {
            ans += word1[s1];
            s1++;
        }
        while(s2 < j) {
            ans += word2[s2];
            s2++;
        }
        return ans;
    }
};