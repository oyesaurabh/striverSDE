[Link](https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1)
# Flattening a Linked List 
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:<br>
(i) a next pointer to the next node,<br>
(ii) a bottom pointer to a linked list where this node is head.<br>
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.<br> 
***Note:*** The flattened list will be printed using the bottom pointer instead of next pointer.<br>
***Example 1:***<br>
```
Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
```
***Example 2:***<br>
```
Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
```
## Solution : Merge Sort FTW
Time Complexity: O(N)<br>
Space Complexity: O(1)
```cpp
Node *flatten(Node *root)
{
   // Your code here
   
}
```
