class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>count(26 , 0);
        vector<bool>instack(26 , false);
        //unique
        for(char ch : s){
            count[ch -'a']++;
        }
        stack<int>st;
        for(char ch : s){
            count[ch-'a']--;
            //lexographical
       // Prevents Duplicate Insertio
        if(instack[ch-'a']){
            continue;
        }
      //   count[st.top()-'a'] exist karta aage string me ya nahi 
        while(!st.empty() && st.top() > ch &&  count[st.top()-'a'] > 0){
              instack[st.top()-'a']=false;
            st.pop();
          
        }
        st.push(ch);
        instack[ch-'a'] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};