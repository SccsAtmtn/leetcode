class TNode {
public:
    int val, size;
    TNode * left, * right;
    TNode(int val):val(val), size(1), left(NULL), right(NULL) {}
};
class MedianFinder {
public:

    TNode * root = NULL;
    // Adds a number into the data structure.
    void addNum(int num) {
        TNode * node = new TNode(num);
        TNode * parent, * current = root;
        if (root==NULL) {
            root = node;
        }
        else {
            while (current!=NULL) {
                parent = current;
                ++ parent->size;
                if (node->val<current->val) current = current->left;
                else current = current->right;
            }
            if (node->val<parent->val) parent->left = node;
            else parent->right = node;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (root==NULL) return 0;
        int total = root->size;
        if (total%2==0) {
            int num1 = findNthNumber(root, total/2);
            int num2 = findNthNumber(root, total/2+1);
            return ((double)(num1+num2))/2;
        }
        else return (double)findNthNumber(root, total/2+1);
    }
    int findNthNumber(TNode * node, int n) {
        int leftNum = (node->left==NULL)?0:node->left->size;
        if (n<=leftNum) return findNthNumber(node->left, n);
        else 
            if (n==leftNum+1) return node->val;
            else return findNthNumber(node->right, n-leftNum-1);
    }
};