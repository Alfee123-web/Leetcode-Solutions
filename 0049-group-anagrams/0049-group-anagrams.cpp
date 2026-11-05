class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mp;
        for(string s : strs){
            string sortedStr = s;
            sort(sortedStr.begin() , sortedStr.end());
            mp[sortedStr].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto& pair : mp){
            ans.push_back(pair.second);
        }
        return ans;

    }
};
//MAP STATE
// {
//   "aet": ["eat", "tea", "ate"],
//   "ant": ["tan", "nat"],
//   "abt": ["bat"]
// }