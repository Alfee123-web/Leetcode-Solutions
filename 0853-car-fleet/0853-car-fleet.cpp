class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int,int>>cars(n);
        for(int i = 0; i< n ;i++){
            cars[i] = {position[i] , speed[i]};
        }
        std::sort(cars.begin(),cars.end(),[](const auto &a , const auto&b){
        return a.first > b.first;
        //descending order sort by car position
    });
        int fleet = 0;
        double maxT = 0.0;
        for(int i = 0; i < n ; i++){
            double time = (double)(target-cars[i].first)/cars[i].second;
            //time = target - pos / speed
            if(time > maxT){
                maxT = time;
                fleet++;
            }
        }
return fleet;
    }
};