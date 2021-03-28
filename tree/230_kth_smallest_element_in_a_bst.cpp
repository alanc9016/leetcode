class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {        
        if (root == nullptr)
            return -1;

        stack<TreeNode*> stack;

        while (root != nullptr || !stack.empty()) {
            while (root) {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            if (--k == 0)
                return root->val;
            root = root->right;
        }

        return -1;
    }
};
