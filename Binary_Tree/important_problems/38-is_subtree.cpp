/*Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
*/

 bool isSame(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;


        if(node1->val == node2->val)
            return isSame(node1->left, node2->left) && isSame(node1->right, node2->right);
        else
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(isSame(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
