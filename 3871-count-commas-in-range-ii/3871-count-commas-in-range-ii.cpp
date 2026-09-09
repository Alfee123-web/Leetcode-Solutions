class Solution {
public:
    long long countCommas(long long n) {
        long long c =0;
        long long start = 1000;
        long long comperN = 1;
        while(start <= n){
            long long next = start * 1000;
            long long end = min(n,next-1);
            if(end >= start){
                c += (end - start + 1) * comperN;
            }
            start= next;
            comperN++;
        }
        return c;
    }
};