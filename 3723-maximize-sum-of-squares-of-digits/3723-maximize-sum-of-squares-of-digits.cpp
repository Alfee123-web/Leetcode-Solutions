class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(sum > 9LL * num){
            return "";
        }
        int nines = sum / 9;
        int rest = sum % 9;//remainder
        for(int i = 0;i < nines; i++){
               ans += '9';
        }
       
        if(rest > 0){
           ans += to_string(rest);
        }
        while(ans.length() < num){
            ans += '0';//3 0 
        }
      return ans;
    }
};