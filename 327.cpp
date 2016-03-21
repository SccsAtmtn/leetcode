class Solution {
public:
    class binaryNode {
    public:
        double val;
        int size;
        binaryNode * left, * right;
        binaryNode(double x):val(x), size(1), left(NULL), right(NULL) {};
    };
    binaryNode * root = new binaryNode(0);
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) 
            return (nums[0]>=lower && nums[0]<=upper)?1:0;
        vector<double> sum(n, 0);
        sum[0] = nums[0];
        for (int i=1; i<n; ++i) 
            sum[i] = sum[i-1]+nums[i];
        int ans = 0;
        for (int i=0; i<n; ++i) {
            ans += countLess(sum[i]-lower+1)-countLess(sum[i]-upper);
            insert(sum[i]);
        }
        return ans;
    }
    void insert(double val) {
        binaryNode * node = new binaryNode(val);
        binaryNode * current = root, * pre = NULL;
        while (current!=NULL) {
            pre = current;
            ++ current->size;
            if (current->val>=val) current = current->left;
            else current = current->right;
        }
        if (pre->val>=val) pre->left = node;
        else pre->right = node;
    }
    int countLess(double val) {
        binaryNode * current = root;
        int total = 0;
        while (current!=NULL) {
            if (current->val<val) {
                ++ total;
                if (current->left!=NULL) 
                    total += current->left->size;
                current = current->right;
            }
            else
                current = current->left;
        }
        return total;
    }
};