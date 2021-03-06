class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ans = (C-A)*(D-B)+(G-E)*(H-F);
        int overlap = 0;
        if (min(C, G)>max(A, E) && min(D, H)>max(B, F))
            overlap = (min(C, G)-max(A, E))*(min(D, H)-max(B, F));
        return ans-overlap;
    }
};