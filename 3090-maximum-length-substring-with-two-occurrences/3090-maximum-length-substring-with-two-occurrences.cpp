class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(128,0);
        int l = 0;
        int maxl = 0;
        for(int i = 0;i < s.length();i++){
               freq[s[i]]++;
               while(freq[s[i]] > 2){
               freq[s[l]]--;
                 l++;
               }
             maxl = max(maxl , i-l+1);
        }
        return  maxl;
    }
};