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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> dp;
        
        for(Interval interval : intervals) {
            dp[interval.start]++;
            dp[interval.end]--;
        }

        int curr = 0;
        int ans = 0;
        for(auto &i : dp) {
            curr += i.second;
            ans = max(ans, curr);
        }

        return ans;
    }
};
