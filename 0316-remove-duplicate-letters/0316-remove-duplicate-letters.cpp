class Solution {
public:
    string removeDuplicateLetters(string s) {
//freq count
        vector<int> freq(26, 0);
        for (char ch : s) {

            freq[ch - 'a']++;
        }
        //track vis element
        vector<bool> res(26, false);
        string ans = "";
        for (char ch : s) {
            freq[ch - 'a']--;

        if (res[ch - 'a']) {
            continue;
        }
        //Lexicographical Order
        while(!ans.empty() && ans.back() > ch && freq[ans.back()-'a'] > 0){
            res[ans.back()-'a']=  false;
            ans.pop_back();
        }
        ans.push_back(ch);
        res[ch - 'a'] = true;
    }
    return ans;
}
}
;