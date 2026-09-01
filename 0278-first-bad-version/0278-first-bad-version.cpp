// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        while(s<e){
            int m = s + (e-s)/2;
            if(isBadVersion(m)){//bad or good
                e = m;
            }else{
                s = m+1;//good 
            }
        }
        return s;
    }
};