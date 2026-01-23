/*logic :- first create a func of pre order using recursion(inside this func 
create a vector of TreeNode which stores the value of each nodes)

and then call the func and then just simpy perform asuming like an array 
and also left always null goes only right . for last ele both null (left&right)*/

//ps:-114. Flatten Binary Tree to Linked List
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        
        vector<TreeNode*> nodeList;
        preorder(root, nodeList);
        
        for(int i = 0; i < nodeList.size() - 1; i++) {
            TreeNode* current = nodeList[i];
            TreeNode* nextNode = nodeList[i + 1];
            
            current->left = NULL;
            current->right = nextNode;
        }
        
        TreeNode* last = nodeList.back();
        last->left = NULL;
        last->right = NULL;
    }

    void preorder(TreeNode* node, vector<TreeNode*>& list) {
        if (node == NULL) return;
        
        list.push_back(node);
        preorder(node->left, list);
        preorder(node->right, list);
    }
};