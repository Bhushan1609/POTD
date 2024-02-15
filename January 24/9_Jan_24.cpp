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
    void recursion(vector<int>& vec , TreeNode* root){
        if(!root) return;
        if(!root -> left and !root -> right)
            vec.push_back(root->val);
        recursion(vec , root -> left);
        recursion(vec , root -> right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> vec1 , vec2;
        recursion(vec1 , root1);
        recursion(vec2 , root2);
        return vec1==vec2;
    }
};