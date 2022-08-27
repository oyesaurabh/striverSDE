[Link](https://leetcode.com/problems/implement-stack-using-queues/)
# Implement Stack using Queues
Implement a last-in-first-out (LIFO) stack using only two queues. 

## Solution :: using 1 Queue
Time : O(N)
Space : O(N)
```cpp
class Stack {
public:
	queue<int> que;
	// Push element x onto stack.
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	int pop() {
		if(que.empty()) return -1;
		int ele=que.front();
		que.pop();
		return pop();
	}

	// Get the top element.
	int top() {
		if(que.empty())return -1;
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};
```
