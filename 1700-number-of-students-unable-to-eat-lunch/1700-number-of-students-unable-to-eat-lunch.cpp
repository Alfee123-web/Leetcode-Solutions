class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>st;
       for(int s : students){
        st.push(s);
       }
       int r = 0;//rotation
       int s = 0;
        while(!st.empty() && r < st.size()){
            if(st.front() == sandwiches[s]){
                st.pop();
                s++;
                r=0;
            }else{
                int t = st.front();
                st.pop();
                st.push(t);
                r ++;
            }
        }
      return st.size();
    }
};