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

//1457. Pseudo-Palindromic Paths in a Binary Tree
class Solution {
public:
    int recursion(TreeNode* root,unordered_map<int,int>&mapp){
        if(!root) return 0;
        if(!root->left and!root->right){
            mapp[root->val]++;
            bool odd=false,ans=true;
            for(auto &[i,j]:mapp){
                if(j&1) {
                    if(odd==true){
                        ans=false;
                        break;
                    } 
                    else{
                        odd=true;
                    }
                }
            }
            mapp[root->val]--;
            if(ans) return 1;
            return 0;
        }
        mapp[root->val]++;
        int leftt = recursion(root->left,mapp);
        int rightt = recursion(root->right,mapp);
        mapp[root->val]--;
        return leftt+rightt;
    }       
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mapp;
        return recursion(root,mapp);
    }
};