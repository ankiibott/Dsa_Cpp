
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        
        int j = 0;
        
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = st.top();
            
            if (node->val != inorder[j]) {
                node->left = new TreeNode(preorder[i]);
                st.push(node->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[j]) {
                    node = st.top();
                    st.pop();
                    j++;
                }
                node->right = new TreeNode(preorder[i]);
                st.push(node->right);
            }
        }
        return root;
    }
};