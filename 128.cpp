class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        hash.clear();
        for (auto iter = nums.begin(); iter!=nums.end(); ++iter) 
            hash.insert(*iter);
        int ans = 0;
        for (auto iter = nums.begin(); iter!=nums.end(); ++iter)
            ans = max(ans, length(*iter, -1)+length(*iter+1, 1));
        return ans;
    }
private:
    unordered_set<int> hash;
    int length(int num, int delta) {
        int count = 0;
        for (auto iter = hash.find(num); iter!=hash.end(); iter = hash.find(num)) {
            ++count;
            hash.erase(iter);
            num += delta;
        }
        return count;
    } 
};