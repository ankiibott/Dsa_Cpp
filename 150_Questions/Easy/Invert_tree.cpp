//logic:- recursive approach, swap and then call 
// root->left and root->right recursively
//ps:-226. Invert Binary Tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};