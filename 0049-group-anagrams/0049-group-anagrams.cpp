class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<pair<string,int>>sortedstrs(n);

        for(int i = 0; i < n ; i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            sortedstrs[i] = {s,i};
        }
            sort(sortedstrs.begin(),sortedstrs.end());

            vector<vector<string>>res;
            vector<string>currGrp;

            for(int i = 0; i < n ; i++){
                currGrp.push_back(strs[sortedstrs[i].second]);

                if(i == n-1 || sortedstrs[i].first != sortedstrs[i+1].first){
                    res.push_back(currGrp);
                    currGrp.clear();
                }
            }
            return res;
        
    }
};