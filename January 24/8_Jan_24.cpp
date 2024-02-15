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
    void recursion(TreeNode* root , int low , int high , int& ans ){
        if(!root) return ;
        if(root -> val >= low and root -> val <= high) ans += root -> val;
        recursion(root -> left , low , high , ans);
        recursion(root -> right , low , high , ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        recursion(root , low , high , ans);
        return ans;
    }
};