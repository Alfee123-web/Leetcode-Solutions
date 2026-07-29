class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i = 0; i< operations.size();i++){
            
            if(operations[i]== "+"){
                int t1 = st.top(); st.pop();
                int t2 = st.top(); 
                st.push(t1);
                st.push(t1 + t2);
            }else if(operations[i] == "C"){
                st.pop();
            }else if(operations[i] == "D"){
                int t1 = st.top(); 
                st.push(t1 * 2);
            }else{
                st.push(stoi(operations[i]));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};