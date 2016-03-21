class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return(vector<int>(1, 0));
        vector<int> degree(n, 0);
        vector<vector<int> > nodeEdge(n, vector<int>());
        for (int i = 0; i<edges.size(); ++i) {
            ++degree[edges[i].first];
            ++degree[edges[i].second];
            nodeEdge[edges[i].first].push_back(edges[i].second);
            nodeEdge[edges[i].second].push_back(edges[i].first);
        }
        vector<int> leaves;
        for (int i = 0; i < n; ++i)
            if (degree[i] == 1)
                leaves.push_back(i);
        int tot = n;
        while (tot>2) {
            int i;
            vector<int> tmp;
            for (i = 0; i < leaves.size(); ++i) {
                degree[leaves[i]] = 0;
                --tot;
                for (int j = 0; j < nodeEdge[leaves[i]].size(); ++j) {
                    --degree[nodeEdge[leaves[i]][j]];
                    if (degree[nodeEdge[leaves[i]][j]] == 1)
                        tmp.push_back(nodeEdge[leaves[i]][j]);
                }
            }
            leaves = tmp;
        }
        return leaves;
    }
};