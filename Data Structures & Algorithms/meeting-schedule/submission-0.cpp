/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int, int> dp;
        
        for(Interval interval : intervals) {
            dp[interval.start]++;
            dp[interval.end]--;
        }

        int prev = 0;
        for(auto &i : dp) {
            i.second += prev;
            if(i.second > 1)
                return false;
            prev = i.second;
        }
        return true;
    }
};
