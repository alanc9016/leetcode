class Solution {
public:
    bool isValidBST(TreeNode* root) {        
        if (root == nullptr)
            return true;
        stack<TreeNode*> stack;
        TreeNode* prev = nullptr;

        while (root != nullptr || !stack.empty()) {
            while (root) {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            if (prev != nullptr && prev->val >= root->val)
                return false;

            prev = root;
            root = root->right;
        }

        return true;
    }
};
