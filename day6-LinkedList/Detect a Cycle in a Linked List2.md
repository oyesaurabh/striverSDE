[Link](https://leetcode.com/problems/linked-list-cycle-ii/)
# Linked List Cycle ii
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.<br>

***Example***<br>
![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)
```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```
## Solution 1 : Hashing
Time : O(N)<br>
Space : O(N)
```cpp
    ListNode* detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head){
            if(set.find(head) != set.end() )
                return head;
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)return head;
        ListNode *slow,*fast;
        slow=fast=head;
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast)
                fast=fast->next;
        }while(fast && fast != slow);
        if(fast==NULL)return NULL; //no cycle
        fast=head;
        while(fast != slow){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
   
    }
```
