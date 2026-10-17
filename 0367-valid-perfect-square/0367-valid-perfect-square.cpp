class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int s = 1;
        int e = num;//16
        while(s <= e){
            long long m = s + (e-s)/2;//8
            if(m * m == num){
                return true;
            }else if(m * m  < num){
                s = m + 1;
            }else{
                e = m-1;
            }
        }
        return false;
    }
};