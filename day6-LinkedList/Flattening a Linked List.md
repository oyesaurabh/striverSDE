[Link](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1)
# Flattening a Linked List 
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:<br>
(i) a next pointer to the next node,<br>
(ii) a bottom pointer to a linked list where this node is head.<br>
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.<br> 
***Note:*** The flattened list will be printed using the bottom pointer instead of next pointer.<br>
***Example 1:***<br>
```
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
```
***Example 2:***<br>
```
Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
```
## Solution : Multiset
Time Complexity: O(N)<br>
Space Complexity: O(N)
```cpp
Node *flatten(Node *root){
   // Your code here
    multiset<int> set;
    for(Node *r=root;r;r=r->next)
        for(Node *t=r;t;t=t->bottom)
            set.insert(t->data);
    
    Node *ans=new Node(0);
    Node *ptr=ans;
    for(auto it:set){
        ptr->bottom=new Node(it);
        ptr=ptr->bottom;
    }
    return ans->next;
}
```

## Solution : MergeSort FTW 
Time Complexity: O(N)<br>
Space Complexity: O(1), ignoring recursion calls 
```cpp
Node* mergsort(Node *l1,Node *l2){
    Node *head;
    if(l1->data <= l2->data){
        head=l1;
        l1=l1->bottom;
    }
    else{
        head=l2;
        l2=l2->bottom;
    }
    Node *t=head;
    while(l1 && l2){
        if(l1->data <= l2->data)
            t->bottom=l1,l1=l1->bottom;
        else
            t->bottom=l2,l2=l2->bottom;
        t=t->bottom;
    }
    if(l1)t->bottom=l1;
    if(l2)t->bottom=l2;
    return head;
}
Node *flatten(Node *root){
   // Your code here
    if(root==NULL || root->next==NULL)return root;
    root->next=flatten(root->next);
    root=mergsort(root,root->next);
    return root;
}
```