class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1 ) return 1; 
        int c = 0;
        int n1 = 1;
        int n2 = 0;
        for(int i = 2 ; i <= n ; i++){
            c = n1 + n2;
            n2 = n1;//forward shift
            n1 = c;
        }
        return c;
    }
};