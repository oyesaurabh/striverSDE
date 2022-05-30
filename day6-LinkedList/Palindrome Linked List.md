[Link](https://leetcode.com/problems/palindrome-linked-list/)
# Palindrome Linked Lists
Given the head of a singly linked list, return true if it is a palindrome.<br>
***Example***
![img](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)
```
Input: head = [1,2,2,1]
Output: true
```
## Solution: Using the extra data structure
Time Complexity: O(N)
<br>
Space Complexity: O(N)
```cpp
bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }
    int i=0,j=arr.size()-1;
    while(i<j)
        if(arr[i++] != arr[j--])
            return false;
    return true;
}
```
## Solution 2: Optimized Solution
Time Complexity: O(N/2)+O(N/2)+O(N/2)
<br>
Space Complexity: O(1)
```cpp
    ListNode* rev(ListNode *head){
        ListNode* prev = nullptr;
        while(head !=nullptr){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return 1;
        ListNode *p,*q;
        p=q=head;
        while(q && q->next){
            q=q->next->next;
            p=p->next;
        }
        p=rev(p);
        q=head;
        while(p){
            if(p->val != q->val)return 0;
            p=p->next;
            q=q->next;
        }
        return 1;
    }
```