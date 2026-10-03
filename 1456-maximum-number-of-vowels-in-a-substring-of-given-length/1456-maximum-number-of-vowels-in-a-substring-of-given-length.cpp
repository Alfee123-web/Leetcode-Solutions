class Solution {
public:
    int maxVowels(string s, int k) {
        int maxC =0;
          int c = 0;
        int n = s.length();//9

        for(int i = 0; i < k; i++){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    c++;
                }
        }
                maxC = c;

                for(int i = k; i < n;i++){
                    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    c++;
                    }
                      if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){
                    c--;
                      }
                  
                maxC = max(maxC,c);
             }

        return maxC;
    }
};