class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int ins = 0;
        for(char ch : s){
            if(ch == '('){
                if(ins % 2 != 0){
                    ans++;
                     ins--;

                }
                ins +=2;
            }else{
                ins--;
                if(ins < 0){
                    ans++;
                    ins += 2;
                }
            }
        }
        return ins + ans;
    }
};