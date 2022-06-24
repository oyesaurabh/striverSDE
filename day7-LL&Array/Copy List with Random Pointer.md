[Link](https://leetcode.com/problems/copy-list-with-random-pointer/)
#  Copy List with Random Pointer
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.<br>

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.<br>
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:<ul>
<li>val: an integer representing Node.val</li>
<li>random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.</li>
</ul>
<br>
Your code will only be given the head of the original linked list.<br><br>

***Example***
<br>

![img](https://assets.leetcode.com/uploads/2019/12/18/e1.png)

```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```
## Solution : Brute Force
Time : O(2N)<br>
Space : O(N)
```cpp
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* t=head;
        while(t){
            Node *newNode=new Node(t->val);
            mp[t]=newNode;
            t=t->next;
        }
        t=head;
        while(t){
            mp[t]->next=mp[t->next];
            mp[t]->random=mp[t->random];
            t=t->next;
        }
        return mp[head];
    }
```

## Solution : Most Optimized
Time : O(3N)
Space : O(1)

```cpp
    Node* copyRandomList(Node* head) {
        Node *t=head;
          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
        while(t){
            Node *newN=new Node(t->val);
            newN->next=t->next;
            t->next=newN;
            t=t->next->next;
        }
          // Second round: assign random pointers for the copy nodes.
        t=head;
        while(t){
            if(t->random)
                t->next->random=t->random->next;
            t=t->next->next;
        }  
          // Third round: restore the original list, and extract the copy list.
        Node *newhead=new Node(0);
        Node *t2=newhead;
        Node *t1=head;
        while(t1){
            t2->next=t1->next;
            t2=t2->next;
            t1->next=t1->next->next;
            t1=t1->next;
        }
        
        return newhead->next;
    }

```