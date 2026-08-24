class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(128,0);
        for(char ch : s){
            freq[ch]++;
        }
        // 1 1 2 2
        sort(s.begin(),s.end(), [&](char a, char b){
            if(freq[a] != freq[b]){
                return freq[a] > freq[b];
            }
            return a > b;
        });
   return s;
    }
};