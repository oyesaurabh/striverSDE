[Link](https://leetcode.com/problems/delete-node-in-a-linked-list/)
# Delete Node in a Linked List
Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
It is guaranteed that the node to be deleted is not a tail node in the list.
<br>
![img](https://assets.leetcode.com/uploads/2020/09/01/node1.jpg)

## Solution: simple code
Time : O(N)<br>
Space : O(1)
```cpp
    void deleteNode(ListNode* node) {
        ListNode *p,*q;
        p=q=node;
        q=q->next;
        while(q->next){
            p->val=q->val;
            p=q;
            q=q->next;
            
        }
        p->val=q->val;
        p->next=NULL;
    }
```
## Solution: more simple code
Time : O(1)<br>
Space : O(1)
```cpp
    void deleteNode(ListNode* node) {
        ListNode *t=node->next;    //optional
        node->val=node->next->val;
        node->next=node->next->next;
        delete t;                  //optional
    }
```