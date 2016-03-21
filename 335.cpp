class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        vector<pair<pair<int, int>, pair<int, int>>> one(4, make_pair(make_pair(INT_MIN, INT_MIN), make_pair(INT_MIN, INT_MIN)));
        vector<vector<pair<pair<int, int>, pair<int, int>>>> segments(2, one);
        int n = x.size();
        if (n==0) return false;
        pair<int, int> current(0, 0), dir(0, 1);
        int flag = 0;
        pair<pair<int, int>, pair<int, int>> pre(make_pair(INT_MIN, INT_MIN), make_pair(INT_MIN, INT_MIN));
        for (int i=0; i<n; ++i) {
            pair<int, int> move(dir.first*x[i], dir.second*x[i]);
            pair<int, int> next(current.first+move.first, current.second+move.second);
            if (next==make_pair(0, 0)) return true;
            pair<pair<int, int>, pair<int, int>> seg(current, next);
            int ob1, ob2;
            if (flag==0 || flag==2) {
                ob1 = 1;
                ob2 = 3;
                dir.first = (flag==2)*2-1;
                dir.second = 0;
            }
            else {
                ob1 = 0;
                ob2 = 2;
                dir.first = 0;
                dir.second = (flag==3)*2-1;
            }
            for (int j=0; j<2; ++j) {
                if (segments[j][ob1]!=pre && cross(segments[j][ob1], seg)) return true;
                if (segments[j][ob2]!=pre && cross(segments[j][ob2], seg)) return true;
            }
            if (segments[0][flag].first==make_pair(INT_MIN, INT_MIN)) 
                segments[0][flag] = seg;
            else 
                if (segments[1][flag].first==make_pair(INT_MIN, INT_MIN))
                    segments[1][flag] = seg;
                else {
                    segments[0][flag] = segments[1][flag];
                    segments[1][flag] = seg;
                }
            flag = (flag+1)%4;
            current = next;
            pre = seg;
        }
        return false;
    }
    bool cross(pair<pair<int, int>, pair<int, int>> seg1, pair<pair<int, int>, pair<int, int>> seg2) {
        if (seg1.first==make_pair(INT_MIN, INT_MIN)) return false;
        if (seg2.first==seg2.second) return false;
        if (seg1.first.first==seg1.second.first) 
            swap(seg1, seg2);
        if (seg1.first.first>seg1.second.first)
            swap(seg1.first, seg1.second);
        if (seg2.first.second>seg2.second.second)
            swap(seg2.first, seg2.second);
        if (seg1.first.first<=seg2.first.first && seg1.second.first>=seg2.first.first)
            if (seg2.first.second<=seg1.first.second && seg2.second.second>=seg1.first.second)
                return true;
            else return false;
        else return false;
    }
};