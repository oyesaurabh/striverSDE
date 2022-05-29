[Link](https://leetcode.com/problems/add-two-numbers-ii/)
#  Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.<br>

***EXAMPLE***<br>
![img](https://assets.leetcode.com/uploads/2021/04/09/sumii-linked-list.jpg)
<br>
```
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
```
## Solution 1 (using reverse and add2numbers)
Time : O( N + M + 2max(M,N) )<br>
space : O( 1 ), ignoring the resultant LinkedList 
```cpp
    ListNode* addTwo(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* curr=head;
        int carry=0;
        while(l1 || l2 || carry){
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=(sum>9)?1:0;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;   
        }
        return head->next;
    }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode *head=addTwo(l1,l2);
        return reverseList(head);
    }

```
## Solution 2(Using stack)
Time : O( N + M + max(N, M) )<br>
Space : O( N+M ), ignoring the resultant LinkedList 
```cpp
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr=NULL;
        stack<int> s1;
        stack<int> s2;
        while(l1)s1.push(l1->val),l1=l1->next;
        while(l2)s2.push(l2->val),l2=l2->next;
        int carry=0,sum=0;;
        while( !s1.empty() || !s2.empty() || carry ){
            sum = ( s1.empty()?0:s1.top() ) + ( s2.empty()?0:s2.top() ) + carry;
            if(!s1.empty())
                s1.pop();
            
            if(!s2.empty())
                s2.pop();
            
            carry=(sum>9)?1:0;
            ListNode *temp=new ListNode(sum%10);
            temp->next=curr;
            curr=temp;
        }
        return curr;
    }

```