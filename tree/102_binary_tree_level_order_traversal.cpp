class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == nullptr) {
            return res;
        }
        
        queue<TreeNode*> queue;
        // dummy node to mark end of level
        TreeNode* dummy = new TreeNode(INT_MIN); 
        vector<int> level;
        
        queue.push(root);
        queue.push(dummy);
        
        while (!queue.empty()) {
            TreeNode* curr = queue.front();
            queue.pop();
            
            // if dummy node popped from queue means a level has ended 
            if (curr->val == INT_MIN) {
                res.push_back(level);
                level = vector<int>(0);
                // if queue not empty after removing dummy, meaning a 
                // next level exists
                if (!queue.empty()) {
                    queue.push(dummy);
                }
            } else {
                level.push_back(curr->val);
                
                // kids pushed at back of queue
                if (curr->left) {
                    queue.push(curr->left);
                }
                if(curr->right) {
                    queue.push(curr->right);
                }
            }
        }
        
        
        return res;
    }
};
