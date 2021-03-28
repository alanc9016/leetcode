class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        
         if (root->val < key)
                root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if (root->left == nullptr && root->right == nullptr)
                root = nullptr;
            else if (root->right == nullptr) {
                root = root->left;
            } else if (root->left == nullptr) {
                root = root->right;
            } else {
                TreeNode* min = getMin(root->right);
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }
        
        return root;
    }
    
    TreeNode* getMin(TreeNode* root) {
        if (root == nullptr)
            return root;
        
        while (root->left) {
            root = root->left;
        }
        
        return root;
    }
};
