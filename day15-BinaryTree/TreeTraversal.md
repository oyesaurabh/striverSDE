# Iterative

### preOrder
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
### PostOrder
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
### InOrder
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
### levelOrder
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