//236. Lowest Common Ancestor of a Binary Tree
//Medium
//
//9579
//
//274
//
//Add to List
//
//Share
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//
//
//
//Example 1:
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        path.push_back(root);
        if (root->val == node->val) {
            return true;
        }
        if (root->left != nullptr && findPath(root->left, node, path))
            return true;
        if (root->right != nullptr && findPath(root->right, node, path))
            return true;
        path.pop_back();
        return false;
    }
            
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        vector<TreeNode*> pathP;
        findPath(root, p, pathP);
        vector<TreeNode*> pathQ;
        findPath(root, q, pathQ);
        size_t minSize = min(pathP.size(), pathQ.size());
        size_t i = 0;
        for (; i < minSize; ++i) {
            if (pathP[i]->val != pathQ[i]->val)
                return pathP[i - 1];
        }
        return i != 0 ? pathP[i - 1] : nullptr;
    }
};
