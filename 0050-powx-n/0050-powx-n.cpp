class Solution {
public:
    double myPow(double x, long long n) {
       if(n == 0) return 1.0;
       if(n < 0){
        n = abs(n);
        x = 1/x;
       }
       double halfpower = myPow(x , n/2);
       double hpsquare = halfpower * halfpower;
       if(n%2 != 0 ){
        return x * hpsquare;
       }
       return hpsquare;
       }
};