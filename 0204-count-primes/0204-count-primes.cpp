class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool>isprime(n , true);
        isprime[0] = false;
        isprime[1] = false;
        
      for(int i = 2; i <= n /i ; i++){
            if(isprime[i]){
                 for(long long j = (long long)i * i; j < n ; j += i){
                    isprime[j] = false;
                 }
            }
        }
        int c = 0;
        for(int i = 2; i < n ; i++){
            if(isprime[i]){
                  c++;
            }
        }
        return c;
    }
};