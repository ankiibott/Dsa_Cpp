class Solution {
public:
    int countNodes(TreeNode* root) {
        vector<int> nums;
        Preorder(root, nums);
        return nums.size();
    }

    void Preorder(TreeNode* root, vector<int>& nums) {
        if (root == NULL) return;
        nums.push_back(root->val);
        Preorder(root->left, nums);
        Preorder(root->right, nums);
    }
};