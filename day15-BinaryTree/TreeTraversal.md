# Recursive
### 1. preOrder
O(N) S(N)

```cpp
    void solve(TreeNode *r){
        if(r){
            ans.push_back(r->val);
            solve(r->left);
            solve(r->right);
        }
    }

```
### 2. InOrder
O(N) S(N)

```cpp
    void solve(TreeNode *r){
        if(r){
            solve(r->left);
            ans.push_back(r->val);
            solve(r->right);
        }
    }
```
### 3. PostOrder
O(N) S(N)

```cpp
    void solve(TreeNode *r){
        if(r){
            solve(r->left);
            solve(r->right);
            ans.push_back(r->val);
        }
    }

```
# Iterative

### 1. preOrder 
O(N) S(N)

```cpp
void Tree::preOrder(){
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *n = s.top();
        s.pop();
        cout << n->data << " ";
        if (n->right)
            s.push(n->right);
        if (n->left)
            s.push(n->left);
    }
}
```
### 2. PostOrder
O(N) S(2N)

using 2 stack
```cpp
void Tree::postOrder2stack(){
    //using 2 stack
    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        node *t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left)
            s1.push(t->left);
        if(t->right)
            s1.push(t->right);
    }
    while(!s2.empty()){
        cout<<(s2.top())->data<<" ";
        s2.pop();
    }
}
```
O(N) S(N)

using 1 stack
```cpp

```
### 3. InOrder
O(N) S(N)

```cpp
void Tree::InOrder(){
    stack<node*> s;
    node *t=root;
    while (t || !s.empty())
    {
        if (t){
            s.push(t);
            t = t->left;
        }
        else{
            t = s.top();
            s.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}
```
### 4. levelOrder
O(N) S(N)

```cpp
void Tree::levelOrder(){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *t=q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }
}
``` 