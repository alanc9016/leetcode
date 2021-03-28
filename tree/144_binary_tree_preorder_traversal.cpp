class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if (root == nullptr) {
            return res;
        }
        
        stack<TreeNode*> stack;
        stack.push(root);
        
        while (!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            
            res.push_back(curr->val);
            
            if (curr->right) {
                stack.push(curr->right);
            }
            
            if (curr->left) {
                stack.push(curr->left);
            }
            
        }
        
        return res;
    }
};
