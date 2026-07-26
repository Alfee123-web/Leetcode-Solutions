class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(const string& ch : operations){
            if(ch == "C"){
                st.pop();
            }else if(ch == "D"){
                int top = st.top();
                st.push(2 * top);
            }else if(ch == "+"){
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
           
                int sum = t1 + t2;
                st.push(t1);
                st.push(sum);
            }else{
                st.push(stoi(ch));
            }
        }
        int Tsum = 0;
        while(!st.empty()){
            int top = st.top();
            Tsum += st.top();
            st.pop();
        }
        return Tsum;
    }
};