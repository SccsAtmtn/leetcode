#include "head.h"

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        if (n==0)
            return;
        k = k%n;
        vector<bool> moved(n, false);
        for (int i=0; i<n; ++i)
            if (!moved[i]) {
                int currentIndex = i;
                int currentValue = nums[i];
                int nextIndex = (currentIndex+k)%n;
                while (!moved[nextIndex]) {
                    int nextValue = nums[nextIndex];
                    nums[nextIndex] = currentValue;
                    currentIndex = nextIndex;
                    currentValue = nextValue;
                    moved[currentIndex] = true;
                    nextIndex = (currentIndex+k)%n;
                }
            }
    }
};
