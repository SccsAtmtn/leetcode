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
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> ans;
        if (n==0) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int current = 0;
        while (current<n) {
            int start = intervals[current].start, end = intervals[current].end, next = current+1;
            while (next<n && intervals[next].start<=end) {
                end = max(end, intervals[next].end);
                ++next;
            } 
            ans.push_back(Interval(start, end));
            current = next;
        }
        return ans;
    }
    static bool cmp(Interval a, Interval b) {
        return ((a.start<b.start)||(a.start==b.start && a.end<b.end));
    }
};