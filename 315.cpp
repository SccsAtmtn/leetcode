class Node {
public:
    int val, size;
    Node * left, * right;
    Node(int val):val(val), size(1), left(NULL), right(NULL){}
};
class Solution {
public:
    Node * root;
    vector<int> countSmaller(vector<int>& nums) {
        root = NULL;
        int n = nums.size();
        vector<int> counts(n, 0);
        for (int i=n-1; i>=0; --i) {
            counts[i] = countSmaller(nums[i]);
            Node * node = new Node(nums[i]);
            insertTree(node);
        }
        return counts;
    }
    void insertTree(Node * node) {
        if (root==NULL) {
            root = node;
            return;
        }
        Node * parent, * current = root;
        while (current!=NULL) {
            parent = current;
            ++ parent->size;
            if (current->val>node->val) current = current->left;
            else current = current->right;
        }
        if (parent->val>node->val) parent->left = node;
        else parent->right = node;
    }
    int countSmaller(int val) {
        int tot = 0;
        Node * node = root;
        while (node!=NULL) {
            if (node->val>val) node = node->left;
            else 
                if (node->val==val) {
                    tot += (node->left==NULL)?0:node->left->size;
                    break;
                }
                else {
                    tot += (node->left==NULL)?0:node->left->size;
                    ++ tot;
                    node = node->right;
                }
        }
        return tot;
    }
};