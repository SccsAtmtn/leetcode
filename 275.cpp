class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n==0) return 0;
        for (int i=0; i<n; ++i) {
            if (citations[i]>=n-i && (i==0 || citations[i-1]<=n-i)) return n-i;
        }
        return 0;
    }
};