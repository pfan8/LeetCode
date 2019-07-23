class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root) pathSum(root, sum, {});
        return resp;
    }
    
private:
    void pathSum(TreeNode* node, int acc, std::vector<int> path) {
        if (!node) {
            if (acc == 0) {
                resp.push_back(path);
            }
            return;
        }
        
        path.push_back(node->val);
        acc -= node->val;
        
        if (!node->left && !node->right) {
            // Leaf
            if (acc == 0) {
                resp.push_back(path);
            }
            return;
        }
        
        pathSum(node->left, acc, path);
        pathSum(node->right, acc, path);
    }
    
    std::vector<std::vector<int>> resp;
};