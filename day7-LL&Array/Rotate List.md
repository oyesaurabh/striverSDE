[Link](https://leetcode.com/problems/rotate-list/description/)
# Rotate List
Given the head of a linked list, rotate the list to the right by k places.<br>
***Example***<br>
![img](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)
```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```
## Solution 1 : Brute Force
Time : O(Number of nodes present in the list*k)<br>
Space : O(1)
```cpp
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next)return head;
        int n=0;
        for(ListNode *t=head;t;t=t->next)
            n++;
        k%=n;
        while(k--){
            ListNode *t=head;
            while(t&&t->next&&t->next->next) //going to 2nd last element 
                t=t->next;
            ListNode *end=t->next;
            t->next=NULL;
            end->next=head;
            head=end;
        }
        return head;
    }
```

## Solution 2 : Using additional Array( 200iq )
Time : O( 4N )<br>
Space : O(N)
```cpp
    void rev(vector<int> &a,int i,int j){
        while(i<j)
            swap(a[i++],a[j--]);
        
    }
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k%=n;
        rev(a,0,n-k-1);
        rev(a,n-k,n-1);
        rev(a,0,n-1);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k)return head;
        vector<int> a;
        for(ListNode *t=head;t;t=t->next)
            a.push_back(t->val);
        rotate(a,k);        
        int i=0;
        for(ListNode *t=head;t;t=t->next)
            t->val=a[i++];
        return head;
    }
```
## Solution 3 : Most Optimized
