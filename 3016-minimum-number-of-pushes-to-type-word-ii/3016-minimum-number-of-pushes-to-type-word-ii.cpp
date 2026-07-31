class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
      
        for(char ch : word){
            freq[ch-'a']++;
        }
        int p =0;
        sort(freq.rbegin(),freq.rend());
        for(int i = 0; i < 26 ;i++){
               p += ((i/8) + 1 ) * freq[i];
        }
        return p;
    }
};