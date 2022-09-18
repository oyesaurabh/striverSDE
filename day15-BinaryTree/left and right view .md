# Left view of BT
[Link](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)

first node of every level.
## 1. iterative
O(N)<br>
S( nodes present at diff. level )<br>
```cpp
vector<int> leftView(Node *root)
{

        vector<int> ans;
        if(root==NULL)return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->data);
            while(n--){
                Node *t=q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        return ans;
}
```
## 2. Recursive( better in terms of space complexity )
O(N)<br>
S( height of Tree )<br>
```cpp
void solve(Node *r,int level,vector<int> &ans){
    if(!r)return;
    if(ans.size()==level)
        ans.push_back(r->data);
    solve(r->left,level+1,ans);
    solve(r->right,level+1,ans);
}
vector<int> leftView(Node *root){
        vector<int> ans;
        solve(root,0,ans);
        return ans;
}
```

# Right view of BT
[Link](https://leetcode.com/problems/binary-tree-right-side-view/)

Last node of every level.
## 1. iterative
O(N)<br>
S( nodes present at diff. level )<br>
```cpp
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode *t=q.front();
                q.pop();
                if(n==0)ans.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        return ans;
    }
``` 
## 2. Recursive
O(N)<br>
S( height of Tree )<br>
```cpp
    vector<int> ans;
    void solve(TreeNode *r,int level){
        if(!r)return;
        if(ans.size()==level)
            ans.push_back(r->val);
        solve(r->right,level+1);
        solve(r->left,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return ans;
    }
```