//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
//
//
//
//Example 1:
//
//
//Input: root = [1,2,2,3,4,4,3]
//Output: true
//Example 2:
//
//
//Input: root = [1,2,2,null,3,null,3]
//Output: false
//
//
//Constraints:
//
//The number of nodes in the tree is in the range [1, 1000].
//-100 <= Node.val <= 100
//
//
//Follow up: Could you solve it both recursively and iteratively?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    enum class Direction {
        Neutral,
        Left,
        Right
    };
    
    using NodeVector = vector<pair<int, Direction>>;
    
    void processLeft(TreeNode* node, NodeVector& result, Direction direction) {
        if (node == nullptr)
            return;
        processLeft(node->left, result, Direction::Right);
        processLeft(node->right, result, Direction::Left);
        result.push_back({node->val, direction});
    }
    
    void processRight(TreeNode* node, NodeVector& result, Direction direction) {
        if (node == nullptr)
            return;
        processRight(node->right, result, Direction::Right);
        processRight(node->left, result, Direction::Left);
        result.push_back({node->val, direction});
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        if (root->left == nullptr || root->right == nullptr)
            return false;
        NodeVector leftNodes;
        processLeft(root->left, leftNodes, Direction::Neutral);
        NodeVector rightNodes;
        processRight(root->right, rightNodes, Direction::Neutral);
        return leftNodes == rightNodes;
    }
};
