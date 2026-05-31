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
        if(intervals.empty()) return 0;
        auto com = [](const Interval& a, const Interval& b){
            return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), com);
        priority_queue<int, vector<int>, greater<int>> pq;
        int rooms = 0;
        for(Interval& a : intervals){
            while(!pq.empty() && a.start >= pq.top()){
                pq.pop();
            }      
            pq.push(a.end);
            rooms = max(rooms, (int)pq.size());
        }
        return rooms;
    }
};
