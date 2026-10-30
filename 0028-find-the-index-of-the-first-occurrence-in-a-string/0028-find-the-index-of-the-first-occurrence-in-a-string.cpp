class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();//9
        int m = needle.length();//3
        int i = 0;
        int j = 0;
     
        while (i < n && j < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }else{
                // Mismatch: backtrack i to the next position after the start of the current check, and reset j
                i = i -j  + 1;
                j = 0;
            }
        }
        // If j reached m, we successfully found the entire needle
    
        if(j == m){
            return i-j;
        }
        return -1;
    }
};