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
    void recursion(TreeNode* root , int mini,int maxi,int& ans){
        if(!root)return;
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        ans=max(ans,abs(maxi-mini));
        recursion(root->left,mini,maxi,ans);
        recursion(root->right,mini,maxi,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        recursion(root,1e6,-12,ans);
        return ans;
    }
};