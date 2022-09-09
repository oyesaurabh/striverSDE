[Link](https://leetcode.com/problems/min-stack/)
# Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
<ul>
<li>MinStack() initializes the stack object.</li>
<li>void push(int val) pushes the element val onto the stack.</li>
<li>void pop() removes the element on the top of the stack.</li>
<li>int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.</li>
<li>You must implement a solution with O(1) time complexity for each function.</li>
</ul>
 
```
Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```
## Solution 
Time Complexity: O(1)
Space Complexity: O(2N)
```cpp
class MinStack {
    stack<int> minstack,mainstack;
public:
    MinStack() {}
    
    void push(int val) {
        mainstack.push(val);
        if(minstack.empty() || minstack.top() >= val)
            minstack.push(val);
    }
    
    void pop() {
        if(mainstack.top() == minstack.top() )
            minstack.pop();
        mainstack.pop();
    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
```
## Solution
Time Complexity: O(1)
Space Complexity: O(N)
```cpp

```