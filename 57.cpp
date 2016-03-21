/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        vector<Interval> ans;
        if (n==0) {
            ans.push_back(newInterval);
            return ans;
        }
        int index1 = -1, index2 = -1;
        for (int i=0; i<n; ++i)
            if (intervals[i].end>=newInterval.start) {
                index1 = i;
                break;
            }
        if (index1==-1) {
            ans = intervals;
            ans.push_back(newInterval);
            return ans;
        }
        for (int i=index1; i<n; ++i) 
            if (intervals[i].start>newInterval.end) {
                index2 = i;
                break;
            }
        if (index2==-1) {
            for (int i=0; i<index1; ++i)
                ans.push_back(intervals[i]);
            newInterval.start = min(newInterval.start, intervals[index1].start);
            newInterval.end = max(newInterval.end, intervals.back().end);
            ans.push_back(newInterval);
            return ans;
        }
        else
            if (index2==index1) {
                for (int i=0; i<index1; ++i)
                    ans.push_back(intervals[i]);
                ans.push_back(newInterval);
                for (int i=index1; i<n; ++i)
                    ans.push_back(intervals[i]);
                return ans;
            }
        for (int i=0; i<index1; ++i)
            ans.push_back(intervals[i]);
        newInterval.start = min(newInterval.start, intervals[index1].start);
        newInterval.end = max(newInterval.end, intervals[index2-1].end);
        ans.push_back(newInterval);
        for (int i=index2; i<n; ++i)
            ans.push_back(intervals[i]);
        return ans;
    }
};