class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Days in each month for a non-leap year
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto getDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };

        int aliceArrival = getDayOfYear(arriveAlice);
        int aliceLeave = getDayOfYear(leaveAlice);
        int bobArrival = getDayOfYear(arriveBob);
        int bobLeave = getDayOfYear(leaveBob);

        // Find the overlap interval
        int overlapStart = max(aliceArrival, bobArrival);
        int overlapEnd = min(aliceLeave, bobLeave);

        // Calculate overlapping days
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0;
    }
};