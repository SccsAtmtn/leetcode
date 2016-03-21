class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        int n = prerequisites.size();
        vector<int> degree(numCourses, 0);
        vector<vector<int>> edge(numCourses, vector<int>());
        for (int i=0; i<n; ++i) {
            ++degree[prerequisites[i].first];
            edge[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int> one;
        for (int i=0; i<numCourses; ++i)
            if (degree[i]==0) {
                one.push_back(i);
                ans.push_back(i);
            }
        while (!one.empty()) {
            vector<int> temp;
            for (int i=0; i<one.size(); ++i) 
                for (int j=0; j<edge[one[i]].size(); ++j) {
                    --degree[edge[one[i]][j]];
                    if (degree[edge[one[i]][j]]==0) {
                        temp.push_back(edge[one[i]][j]);
                        ans.push_back(edge[one[i]][j]);
                    }
                }
            one = temp;
        }
        if (ans.size()==numCourses) return ans;
        else return vector<int>();
    }
};