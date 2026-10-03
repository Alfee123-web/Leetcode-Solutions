class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        vector<int>S1(26,0);
        vector<int>S2(26,0);
        for(int i = 0 ; i< n ; i++){
            S1[s1[i]-'a']++;
            S2[s2[i]-'a']++;
           
        }
         if(S1 == S2){
                return true;
            }
        for(int i = n ; i< m ; i++){
              S2[s2[i]-'a']++;
              S2[s2[i-n]-'a']--;
              if(S1 == S2){
                return true;
              }
        }
        return false;
    }

};