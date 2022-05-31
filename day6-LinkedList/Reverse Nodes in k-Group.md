[link](https://leetcode.com/problems/reverse-nodes-in-k-group/)
# Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.<br>
***Example***<br>
![img](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)
```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```
## Solution
Time Complexity: O(N)
<br>
Space Complexity: O(1)
```cpp
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head==NULL || head->next==NULL)return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        int count=0;
        for(ListNode *t=head;t;t=t->next)count++;
        
        ListNode *pre,*cur,*nxt;
        pre=dummy;
        while(count >= k){
            cur=pre->next;
            nxt=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                nxt=cur->next;
            }
            pre=cur;
            count-=k;
        }
        return dummy->next;
    }
```
