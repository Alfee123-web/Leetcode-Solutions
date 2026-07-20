class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> instack(26, false);
        for (char ch : s) {
            count[ch - 'a']++;
        }
        std::stack<char> st;

        for (char ch : s) {
            count[ch - 'a']--;

            if (instack[ch - 'a'])
                continue;
            // order maintain
            while (!st.empty() && st.top() > ch && count[st.top() - 'a'] > 0) {
                instack[st.top() - 'a'] = false;
                st.pop();
            }
            // insert curr element
            st.push(ch);
            instack[ch - 'a'] = true;
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};