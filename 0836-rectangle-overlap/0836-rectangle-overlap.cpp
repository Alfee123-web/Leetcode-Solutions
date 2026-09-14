class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //O area base case : means never overlaps
        if(rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
           rec2[0] == rec2[2] || rec2[1] == rec2[3]){
            return false;
        }

        bool isLeft = rec1[2] <= rec2[0];
        bool isRight = rec1[0] >= rec2[2];
        bool isBelow = rec1[3] <= rec2[1];
        bool isAbove = rec1[1] >= rec2[3];

        return !(isLeft || isRight || isBelow || isAbove);
    }
};