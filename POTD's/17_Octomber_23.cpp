//1361
class Solution {
public:
    // Binary Tree required 
    //     (1) Every child has only one parent 
    //     (2) Only one root
    //     (3) Tree need to connect not make individual tree {1 ,2 3} , {4 ,5}

    // putting child to parent mapping and check have two parent or not
    bool makingParentMapping(vector <int>&leftChild,vector<int>&rightChild,unordered_map<int,int>& childToParent , unordered_map<int , vector <int>>& list){
        int n = leftChild.size();
        for (int i = 0 ; i < n ; i++){
            if(childToParent.find(leftChild[i]) != childToParent.end() ) return false;
            else if(leftChild[i] != -1) {
                childToParent[leftChild[i]] = i;
                list[i].push_back(leftChild[i]);
            }
            if(childToParent.find(rightChild[i]) != childToParent.end() ) return false;
            else if(rightChild[i] != -1) {
                childToParent[rightChild[i]] = i;                        
                list[i].push_back(rightChild[i]);
            }
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // storing child to Parent mapping either if any child have two parent return false
        unordered_map <int , int> childToParent; 

        //making list to traverse                                  
        unordered_map<int , vector <int>> list;

        bool ans = makingParentMapping(leftChild ,  rightChild , childToParent , list);

        
        if(!ans) return ans; // two parent return false
        int root = -1 ;
        int cnt = 0;
        for (int i = 0 ; i < n ; i++){
            if(childToParent.find(i) == childToParent.end()){
                cnt++;
                root = i;
            }
        }
        if(cnt > 1 or root == -1) return false;// if the there are multiple root (> more than one)
       
       
        // Traversal
        queue <int> q ;
        vector <int> visited(n , 0);
        q.push(root);
        visited[root] = 1;
        cnt = 1 ; // counting as root 1  // counting numbers of nodes
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for (auto &i : list[front]){
                if(visited[i] == 0){
                    visited[i] = 1;
                    cnt++;
                    q.push(i); 
                }
            }
        }
        return cnt == n;
    }
};
