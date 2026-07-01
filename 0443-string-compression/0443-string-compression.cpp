class Solution {
public:
    int compress(vector<char>& chars) {

        int i = 0; //read
        int j = 0; //write
       
        while(i < chars.size()){
           char s = chars[i];
           int c = 0;
           while(i < chars.size() && chars[i] == s){
            i++;
            c++;
           }
           chars[j++] = s;
            if(c > 1){
                string ans = to_string(c);
                for(char c : ans){
                    chars[j++] = c;
                }
            }
        }
     return j;
    }
};