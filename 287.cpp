class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast, ans;
        slow = fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow!=fast);
        fast = 0;
        do {
            ans = slow;
            slow = nums[slow];
            fast = nums[fast];
        } while (slow!=fast);
        return nums[ans];
    }
};