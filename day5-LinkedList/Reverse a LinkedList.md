[Link](https://leetcode.com/problems/reverse-linked-list/)

# Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
![eg](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

## Reverse Linked List : Iterative
Time Complexity: O(N)
<br>
Space Complexity: O(1)

```cpp
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*q,*r;
        p=q=NULL;
        r=head;
        while(r){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        return q;
    }
```

## Reverse a Linked List : Recursive
Time Complexity: O(N)
<br>
Space Complexity: O(N)

```cpp
    ListNode* reverseList(ListNode* head) {
        if(head == NULL||head->next==NULL)
            return head;

        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;  
    } 
```
