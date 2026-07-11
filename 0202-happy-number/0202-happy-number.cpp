class Solution {

    int getNext(int n) {
        int s = 0;
        while (n > 0) {
            int dig = n % 10;
            s += dig * dig;
            n = n / 10;
        }

        return s;
    }

public:
    bool isHappy(int n) {
       int slow = getNext(n);
        int fast = getNext(getNext(n));
        while (slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return slow == 1;
    }
};