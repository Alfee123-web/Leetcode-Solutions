class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxL = 0;
        unordered_map<char , int>freq;
        for(int j = 0; j < n ; j++){
            freq[s[j]]++;
            while(freq[s[j]] > 1){
                freq[s[i]]--;
                i++;
            }
            maxL = max(maxL , j - i + 1);
        }
        return maxL;
    }
};