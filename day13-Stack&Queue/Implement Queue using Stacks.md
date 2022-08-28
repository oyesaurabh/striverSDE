[Link](https://leetcode.com/problems/implement-queue-using-stacks/)
# Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks. 
## Solution
Time Complexity: O(N)  
Space Complexity: O(2N)
```cpp
class MyQueue {
    stack<int> s1,s2;
public:
    
    void push(int x) {
       s1.push(x); 
    }
    
    int pop() {
        if(s2.empty())
            while(!s1.empty()){
                int x=s1.top();
                s1.pop();
                s2.push(x);
            }
        int x=s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty())
            while(!s1.empty()){
                int x=s1.top();
                s1.pop();
                s2.push(x);
            }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};
```
