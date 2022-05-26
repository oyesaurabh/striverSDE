[Link](https://leetcode.com/problems/add-two-numbers/)
# Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

***Example:***
![img](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```
## Solution : Elementary Math
***Time Complexity:*** O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
<br>
***Space Complexity:*** O(max(m,n)). The length of the new list is at most max(m,n)+1.

```cpp
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* curr=head;
        int carry=0;
        while(l1 || l2 || carry){
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;   
        }
        return head->next;
    }
```