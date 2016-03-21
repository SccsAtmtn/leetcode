class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "NULL,";
        string ans = intToString(root->val);
        deque<TreeNode *> que;
        que.push_back(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop_front();
            if (node->left == NULL) {
                ans = ans + "NULL,";
            }
            else {
                ans = ans + intToString(node->left->val);
                que.push_back(node->left);
            }
            if (node->right == NULL) {
                ans = ans + "NULL,";
            }
            else {
                ans = ans + intToString(node->right->val);
                que.push_back(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "NULL,") return NULL;
        deque<TreeNode *> que;
        int index1 = 0, index2 = data.find(",");
        string current = data.substr(index1, index2 - index1);
        TreeNode *root = new TreeNode(stringToInt(current));
        que.push_back(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop_front();
            index1 = index2 + 1;
            index2 = data.find(",", index1);
            current = data.substr(index1, index2 - index1);
            if (current != "NULL") {
                TreeNode * son = new TreeNode(stringToInt(current));
                node->left = son;
                que.push_back(son);
            }
            index1 = index2 + 1;
            index2 = data.find(",", index1);
            current = data.substr(index1, index2 - index1);
            if (current != "NULL") {
                TreeNode *son = new TreeNode(stringToInt(current));
                node->right = son;
                que.push_back(son);
            }
        }
        return root;
    }
    string intToString(int num) {
        if (num == 0) return "0,";
        string ans = "";
        bool flag = false;
        if (num<0) {
            flag = true;
            num = -num;
        }
        while (num>0) {
            ans = (char)(num % 10 + 48) + ans;
            num = num / 10;
        }
        if (flag) ans = "-" + ans;
        ans = ans + ",";
        return ans;
    }
    int stringToInt(string str) {
        bool flag = false;
        if (str[0] == '-') {
            flag = true;
            str.erase(0, 1);
        }
        int ans = 0;
        for (int i = 0; i<str.length(); ++i) {
            ans = ans * 10 + (int)str[i] - 48;
        }
        if (flag) ans = -ans;
        return ans;
    }
};