class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         vector<int>ans;
           int n = s.length();
           int m = p.length();
             if(m > n) return ans;
          
         
           vector<int>freqS1(26 ,0);
           vector<int>freqS2(26,0);

       
           for(int i = 0; i < m; i++){
               freqS1[s[i]-'a']++;
               freqS2[p[i]-'a']++;

           }
           if(freqS1 == freqS2){
            ans.push_back(0);
           }
           for(int i = m ; i < n ; i++){
            freqS1[s[i]-'a']++;
            freqS1[s[i-m]-'a']--;
            if(freqS1 == freqS2){
                ans.push_back(i-m+1);
            }
           }
           return ans;
    }
};