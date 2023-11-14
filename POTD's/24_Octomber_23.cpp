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
 //515
class Solution {
public:
    vector <int> levelorder(TreeNode* &root){
        vector <int> dummy;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int maxi = INT_MIN;
        vector <int> answer;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                answer.push_back(maxi);
                maxi = INT_MIN;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                maxi = max(maxi , temp -> val);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }
        return answer;
    }
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        if(root -> left == NULL and root -> right == NULL) return {root -> val};
        return levelorder(root);
    }
};
