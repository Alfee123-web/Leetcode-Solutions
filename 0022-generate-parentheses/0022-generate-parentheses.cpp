class Solution {
    void backtrack(string curr , int o,  int c , int n , vector<string>&ans){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(o < n){
            backtrack(curr + "(" , o + 1, c , n , ans);
        }
        if(c < o){
            backtrack(curr + ")" , o , c+1 , n , ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        backtrack("" , 0 , 0 , n , ans);
        return ans;
    }
};