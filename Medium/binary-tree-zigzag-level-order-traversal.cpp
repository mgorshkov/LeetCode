//103. Binary Tree Zigzag Level Order Traversal
//Medium
//
//5932
//
//170
//
//Add to List
//
//Share
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
//
//
//
//Example 1:
//
//
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[20,9],[15,7]]
//Example 2:
//
//Input: root = [1]
//Output: [[1]]
//Example 3:
//
//Input: root = []
//Output: []
//
//
//Constraints:
//
//The number of nodes in the tree is in the range [0, 2000].
//-100 <= Node.val <= 100

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            auto size = q.size();
            vector<int> level;
            for (auto i = 0; i < size; ++i) {
                auto element = q.front();
                q.pop();
                if (element->left) {
                    q.push(element->left);
                }
                if (element->right) {
                    q.push(element->right);
                }
                if (leftToRight)
                    level.push_back(element->val);
                else
                    level.insert(std::begin(level), element->val);
            }
            leftToRight = !leftToRight;
            res.push_back(level);
        }
        return res;
    }
};
