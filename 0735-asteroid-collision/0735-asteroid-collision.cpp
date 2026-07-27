class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(int i : asteroids){
            if(i > 0){
                ans.push_back(i);
            }else{
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(i)){
                    //positive small ones pop 
                    ans.pop_back();
                }
                if(ans.empty() || ans.back() < 0){
                    ans.push_back(i);
                }else if(ans.back() == abs(i)){
                    ans.pop_back();
                }else{

                }
            }
        }
        return ans;
    }
};