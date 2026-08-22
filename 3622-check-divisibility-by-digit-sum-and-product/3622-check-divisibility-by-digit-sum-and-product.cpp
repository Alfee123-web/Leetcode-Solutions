class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        int temp = n;
        while(temp > 0){
            int dig = temp % 10;
            sum += dig;//5
            mul *= dig;//6
            temp = temp/10;
        }
      int ans = sum + mul;
      if(n % ans == 0){
        return true;
      }
         return false;
    }
};