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
    void createParentNoding(TreeNode* root,TreeNode* &startNode,int start,unordered_map<TreeNode*,TreeNode*>&childParent){
        if(!root)return;
        if(root->left) childParent[root->left]=root;
        if(root->right) childParent[root->right]=root;
        if(root->val==start) startNode=root;
        createParentNoding(root->left,startNode,start,childParent);
        createParentNoding(root->right,startNode,start,childParent);
    }
    int amountOfTime(TreeNode* root, int start) {
        int time=0;
        TreeNode* startNode=NULL;
        unordered_map<TreeNode*,TreeNode*>childParent;
        unordered_map<TreeNode*,int>visited;
        createParentNoding(root,startNode,start,childParent);
        queue<TreeNode*>q;
        q.push(startNode);
        visited[startNode]++;
        while(!q.empty()){
            int size=q.size();
            bool change=false;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left and !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left]++;
                    change=true;
                }
                if(node->right and !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]++;
                    change=true;
                }
                if(childParent[node] and !visited[childParent[node]]){
                    q.push(childParent[node]);
                    visited[childParent[node]]++;
                    change=true;
                }
            }
            if(change) time++;
        }
        return time;
    }
};