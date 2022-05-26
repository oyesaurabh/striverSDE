[Link](https://leetcode.com/problems/merge-two-sorted-lists/)
# Merge two sorted Linked Listss
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
![img](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```
## Solution 1: Using an externally linked list to store answers.
(***NOT WORTH LOOKING***)<br>
Time : O(N+M)<br>
Space : O(N+M)
```cpp
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)return NULL;
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *newhead;
        if(l2->val >= l1->val){
            newhead=new ListNode(l1->val);
            l1=l1->next;
        }
        else{
            newhead=new ListNode(l2->val);
            l2=l2->next;
        }
        ListNode *curr=newhead;
        while(l1 && l2){
            if(l1->val <= l2->val)
                curr->next=new ListNode(l1->val),l1=l1->next;
            else 
                curr->next=new ListNode(l2->val),l2=l2->next;
            curr=curr->next;
        }
        while(l1)
            curr->next=new ListNode(l1->val),l1=l1->next,curr=curr->next;
        while(l2)
             curr->next=new ListNode(l2->val),l2=l2->next,curr=curr->next;
        
        return newhead;
    }
```
## Solution 2: using Merge_Sort
Time : O(N+M)<br>
Space : O(1)
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)return NULL;
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *head,*curr;
        if(l2->val >= l1->val){
            head=l1;
            l1=l1->next;
        }
        else{
            head=l2;
            l2=l2->next;
        }
        curr=head;
        while(l1 && l2){
            if(l1->val <= l2->val)
                curr->next=l1,l1=l1->next;
            else 
                curr->next=l2,l2=l2->next;
            curr=curr->next;
        }
        if(l1)
            curr->next=l1;
        if(l2)
            curr->next=l2;
        return head;
    }
```
