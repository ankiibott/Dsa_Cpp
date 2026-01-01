//Note:- recursive and then perform inorder for sum 
//ps-563

class Solution {
public:
    int totalTilt = 0;

    int findTilt(TreeNode* root) {
        totalTilt = 0;
        getSum(root);
        return totalTilt;
    }

private:
    int getSum(TreeNode* node) {
        if (!node) return 0;

        int leftSum = getSum(node->left);
        int rightSum = getSum(node->right);

        totalTilt += abs(leftSum - rightSum);

        return node->val + leftSum + rightSum;
    }
};