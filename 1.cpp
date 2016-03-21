static bool cmp(const pair<int, int>& first, const pair<int, int>& second) {
    return first.first<=second.first;
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        vector<pair<int, int>> numIndex;
        for (int i=0; i<n; ++i)
            numIndex.push_back(make_pair(nums[i], i));
        sort(numIndex.begin(), numIndex.end(), cmp);
        int first = 0, second = n-1;
        while (true) {
            while (first<second && numIndex[first].first+numIndex[second].first<target)
                ++first;
            if (numIndex[first].first+numIndex[second].first==target) {
                ans.push_back(numIndex[first].second+1);
                ans.push_back(numIndex[second].second+1);
                if (ans[0]>ans[1])
                    swap(ans[0], ans[1]);
                return ans;
            }
            while (first<second && numIndex[first].first+numIndex[second].first>target)
                --second;
            if (numIndex[first].first+numIndex[second].first==target) {
                ans.push_back(numIndex[first].second+1);
                ans.push_back(numIndex[second].second+1);
                if (ans[0]>ans[1])
                    swap(ans[0], ans[1]);
                return ans;
            }
        }
    }
};