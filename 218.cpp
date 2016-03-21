class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int, int>> height, ans;
        for (int i=0; i<n; ++i) {
            height.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            height.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(height.begin(), height.end(), cmp);
        multiset<int> tree;
        tree.insert(0);
        int preHeight = 0;
        for (int i=0; i<height.size(); ++i) {
            if (height[i].second<0) 
                tree.insert(-height[i].second);
            else {
                auto ptr = tree.find(height[i].second);
                tree.erase(ptr);
            } 
            auto ptr = tree.end();
            --ptr;
            int curHeight = *ptr;
            if (curHeight!=preHeight) {
                ans.push_back(make_pair(height[i].first, curHeight));
                preHeight = curHeight;
            }
        }
        return ans;
    }
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return (a.first<b.first) || (a.first==b.first && a.second<b.second);
    }
};