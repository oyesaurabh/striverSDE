[Link](https://leetcode.com/problems/copy-list-with-random-pointer/)
#  Copy List with Random Pointer
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.<br>

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.<br>
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:<ul>
<li>val: an integer representing Node.val</li>
<li>random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.</li>
</ul>
<br>
Your code will only be given the head of the original linked list.<br><br>

***Example***
<br>

![img](https://assets.leetcode.com/uploads/2019/12/18/e1.png)

```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

