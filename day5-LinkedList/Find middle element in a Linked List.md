[Link](https://leetcode.com/problems/middle-of-the-linked-list/)
# Find middle element in a Linked List
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```
## Solution 1: Naive Approach
We can traverse through the Linked List while maintaining a count of nodes let’s say in variable n , and then traversing for 2nd time for n/2 nodes to get to the middle of the list.<br>
Time: O(2N)<br>
Space : O(1)
```cpp
ListNode* middleNode(ListNode* head) {
        int c=0;
        ListNode *t;
        for(t=head;t;t=t->next)
            c++;
        t=head;
        for(int i=0;i<c/2;i++)
            t=t->next;
        return t;
    }
```

## Solution 2: [Efficient] Tortoise-Hare-Approach
1. two pointers slow and fast
2. fast=fast->next->next and slow=slow->next;
3. when fast==NULL or fast->next==NULL, return slow.<br>

Time: O(N)<br>
Space : O(1)
```cpp
ListNode* middleNode(ListNode* head) {
        if(head==NULL)return head;
        ListNode *p,*q;   //q=hare or rabbit or khhargosh and p=tortoise or turtle or kachhuwa
        p=q=head;
        while(q&&q->next){
            p=p->next;
            q=q->next;
            if(q)q=q->next;
        }
        return p;
    }
```