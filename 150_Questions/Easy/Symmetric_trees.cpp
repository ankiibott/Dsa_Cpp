//ps:_101. Symmetric Tree
//logic:- perform preorder for left part and postorder for right , then reverse 
//right part if now left == right then true else false
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        
        std::reverse(right.begin(), right.end());
        
        return left == right;
    }

    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            ans.push_back(-101); // Null marker
            return;
        }
        
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
    
    void solvepre(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            ans.push_back(-101); // Null marker
            return;
        }
        
        ans.push_back(root->val);
        solvepre(root->left, ans);
        solvepre(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solvepre(root, ans);
        return ans;
    }
};