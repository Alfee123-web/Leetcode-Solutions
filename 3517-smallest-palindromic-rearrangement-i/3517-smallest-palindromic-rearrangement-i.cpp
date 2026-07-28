class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string l = s.substr(0 , n /2);
        sort(l.begin() , l.end());
        
        string ans = l;
        if(n % 2 == 1){
               ans += s[n/2];
        }
        string r = l;
        reverse(r.begin(),r.end());
        ans += r;
        return ans;
    }
};