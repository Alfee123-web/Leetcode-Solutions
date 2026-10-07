class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxF = 0;
        int maxL =0;

        vector<int>freq(26,0);
        for(int r = 0; r < s.length(); r++){
            freq[s[r]-'A']++;
            maxF = max(maxF , freq[s[r]-'A']);
            
            while((r -l + 1) - maxF > k){
                freq[s[l]-'A']--;
                l++;
            }
            maxL = max(maxL , r-l+1);
        }
        return maxL;
    }
};