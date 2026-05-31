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
        auto com = [](Interval& a, Interval& b){
            return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), com);
        Interval curr = intervals[0];
        for(int i = 1 ; i < intervals.size() ; i++){
            if(curr.end > intervals[i].start) return false;
            curr = intervals[i];
        }
        return true;
    }
};
