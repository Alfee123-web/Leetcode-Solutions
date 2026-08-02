class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int o = 0;
        for(int i = 0 ; i < operations.size() ; i++){
            if(operations[i] == "--X" ||operations[i] == "X--"){
                    o -=1;
            }else{
                o += 1;
            }
        }
        return o;
    }
};