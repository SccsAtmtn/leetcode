class NumArray {
public:
    int n;
    vector<int> segTree;
    NumArray(vector<int> &nums) {
        n = nums.size();
        if (n==0) return;
        for (int i=0; i<2*n; ++i) segTree.push_back(0);
        buildTree(0, 0, n-1, nums);
    }
    void buildTree(int node, int left, int right, vector<int>& nums) {
        if (left==right) {
            segTree[node] = nums[left];
            return;
        }
        int mid = (left+right)/2;
        buildTree(node*2+1, left, mid, nums);
        buildTree(node*2+2, mid+1, right, nums);
        segTree[node] = segTree[node*2+1]+segTree[node*2+2];
    }

    void update(int i, int val) {
        updateTree(0, 0, n-1, i, val);
    }
    void updateTree(int node, int left, int right, int index, int val) {
        if (left==right) {
            segTree[node] = val;
            return;
        }
        int mid = (left+right)/2;
        if (index<=mid) updateTree(node*2+1, left, mid, index, val);
        else updateTree(node*2+2, mid+1, right, index, val);
        segTree[node] = segTree[node*2+1]+segTree[node*2+2];
    }

    int sumRange(int i, int j) {
        return sumTree(0, 0, n-1, i, j);
    }
    int sumTree(int node, int left, int right, int l, int r) {
        if (left>=l && right<=r) {
            return segTree[node];
        }
        int mid = (left+right)/2;
        if (r<=mid) return sumTree(node*2+1, left, mid, l, r);
        else
            if (l>mid) return sumTree(node*2+2, mid+1, right, l, r);
            else return sumTree(node*2+1, left, mid, l, r)+sumTree(node*2+2, mid+1, right, l, r);
    }
};