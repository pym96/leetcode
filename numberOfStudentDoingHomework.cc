class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
            int len = startTime.size();
            
            int sum = 0;

            for(int i = 0; i < len; i++){
                if(startTime[i] <= queryTime && endTime[i] >= queryTime) sum++;
            }

            return sum;
    }
};