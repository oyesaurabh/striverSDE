[Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
# Remove N-th node from the end of a Linked List.
Given the head of a linked list, remove the nth node from the end of the list and return its head.<br>
***Example 1:***
![img](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)
```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```
## Solution 1: Naive Approach [Traverse 2 times]
We can traverse through the Linked List while maintaining a count of nodes, let’s say in variable count , and then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list.<br>
Time : O( 2N)<br>
Space : O( 1 )
>NOT WORTH CODING

## Solution 2: [Efficient] Two pointer method (Slow and Fast)
Time Complexity: O(N)<br>
Space Complexity: O(1) 
```cpp
 ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *f,*s;
        f=s=head;
        while(n--) 
            f = f->next; 

        if(f==NULL)
            return head->next;  //if first element is to be deleted.

        while(f -> next)                  
            f = f -> next, s = s -> next;  

        s -> next = s -> next -> next; 
        return head;

    }
```