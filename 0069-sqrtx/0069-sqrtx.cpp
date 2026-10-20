class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long long s = 1;
        long long e = x;
        long long ans = 0;
        while(s <= e){
            long long m = s + (e-s)/2;//2
            if(m*m == x){
                return m;//2
            }else if(m * m < x){
                ans = m;
                s = m +1;
            }else{
                e = m-1;
            }
        }
        return ans;
    }
};