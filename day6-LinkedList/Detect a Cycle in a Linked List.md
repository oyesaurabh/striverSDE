[Link](https://leetcode.com/problems/linked-list-cycle/)
# Linked List Cycle i
Given head, the head of a linked list, determine if the linked list has a cycle in it.<br>
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.<br>

***Example***<br>
![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)
```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```
## Solution 1 : Hashing
Time : O(N)<br>
Space : O(N)
```cpp
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> set;
    while(head){
        if(set.find(head) != set.end() )
            return 1;
        set.insert(head);
        head=head->next;
    }
    return 0;
}
```

## Solution 2 : Slow and Faster Pointer
Time : O(N)<br>
Space : O(1)
```cpp
bool hasCycle(ListNode *head) {
    if(head==NULL)return 0;
    ListNode *p,*q;
    p=q=head;
    do{
        p=p->next;
        q=q->next;
        if(q)
            q=q->next;
    }while(q && q!=p);
    return q?1:0;  //Null = no cycle, else has cycle
}
```
