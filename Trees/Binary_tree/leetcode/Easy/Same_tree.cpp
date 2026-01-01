//Same Tree
//Ps-100

//note :- use a pair of stack and perfrom pre-order traversal 



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        std::stack<std::pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {
            auto [nodeP, nodeQ] = st.top();
            st.pop();
            if (!nodeP && !nodeQ) continue;
            
            if (!nodeP || !nodeQ || nodeP->val != nodeQ->val) return false;
            st.push({nodeP->right, nodeQ->right});
            st.push({nodeP->left, nodeQ->left});
        }

        return true;
    }
};