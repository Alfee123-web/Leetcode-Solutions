class Solution {
private:
    void helper(int index, int left, int right, int balance, string curr, unordered_set <string> &ans, string &s){
        //BASE CASES
        if(balance < 0) return; //Base Case : dead string
        if(index == s.size()){
            if(left == 0 && right == 0 && balance == 0) ans.insert(curr);
            return; //always return at end of s.
        }

        //Bactrack Part
        char ch = s[index];
        //delete case
        if(ch == '(' && left > 0) helper(index + 1, left - 1, right, balance, curr, ans, s);
        if(ch == ')' && right > 0) helper(index + 1, left, right - 1, balance, curr, ans, s);

        //keep case
        if(ch == '(') balance += 1;
        if(ch == ')') balance -= 1;

        //append and call
        helper(index + 1, left, right, balance, curr + ch, ans, s);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set <string> ans; //to store the the valid orders
        int left_rem = 0, right_rem = 0;
        
        //To get budget for recursion
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(') left_rem++;
            else if(s[i] == ')'){
                if(left_rem > 0) left_rem--;
                else right_rem++; //extra closing bracket
            }
        }

        helper(0, left_rem, right_rem, 0, "", ans, s);
        
        vector <string> res(ans.begin(), ans.end());

        return res;
    }
};