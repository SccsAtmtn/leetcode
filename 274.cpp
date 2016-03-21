class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n==0) return 0;
        sort(citations.begin(), citations.end(), cmp);
        for (int i=n-1; i>=0; --i) {
            if (citations[i]>=i+1 && ((i==n-1)||(citations[i+1]<=i+1))) return i+1;
        } 
    }
    static bool cmp(int a, int b) {
        return a>b;
    }
};