class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
        if (n==0) return true;
        vector<int> one(1, 0);
        vector<vector<int>> degree(numCourses, one);
        for (int i=0; i<n; ++i) {
            ++degree[prerequisites[i].second][0];
            degree[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        one.clear();
        for (int i=0; i<numCourses; ++i) 
            if (degree[i][0]==0) 
                one.push_back(i);
        while (!one.empty()) {
            vector<int> temp;
            for (int i=0; i<one.size(); ++i)
                for (int j=1; j<degree[one[i]].size(); ++j) { 
                    --degree[degree[one[i]][j]][0];
                    if (degree[degree[one[i]][j]][0]==0)
                        temp.push_back(degree[one[i]][j]);
                }
            one = temp;
        }
        for (int i=0; i<numCourses; ++i)
            if (degree[i][0]>0) return false;
        return true;
    }
};