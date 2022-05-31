[link](https://leetcode.com/problems/intersection-of-two-linked-lists/)
# Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:
***Note*** that the linked lists must retain their original structure after the function returns.

***Example 1:***<br>
![img](https://assets.leetcode.com/uploads/2021/03/05/160_example_1_1.png)
```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
```
## Solution 1: Brute-Force
Time : O(M \* N )<br>
space : O(1)
```cpp
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        while(a){
            ListNode *temp=b;
            while(temp){
                if(temp==a)return a;
                temp=temp->next;
            }
            a=a->next;
        }
        return NULL;
    }
```
## Solution 2: Hashing
TIme : O(M + N)<br>
Space : O(N)
```cpp
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        unordered_set<ListNode*> set;
        for(ListNode *t=a;t;t=t->next)set.insert(t);
        for(ListNode *t=b;t;t=t->next)if(set.find(t)!= set.end())return t;
        return NULL;
    }
```
## Solution 3: Most Optimized
Time Complexity: O(2*max( N,M ))<br>
Space Complexity: O(1)
```cpp
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        if(a==NULL || b==NULL)return NULL;
        ListNode *p,*q;
        p=a;
        q=b;
        while(p!=q){
            p=p?p->next:b;
            q=q?q->next:a;
        }
        return p;
    }
```
