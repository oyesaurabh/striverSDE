[Link](https://leetcode.com/problems/valid-parentheses/)
# Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.<br>
***Time*** : O(N)<br>
***Space*** : O(N)<br>
```cpp
    bool isValid(string s) {
        stack<char> stack;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[')
                stack.push(c);
            else{
                if(stack.empty())
                    return 0;
                char top=stack.top();
                if( (top=='('&&c==')') || (top=='{'&&c=='}') || (top=='['&&c==']') )
                    stack.pop();
                else
                    return 0;
            }
        }
        return stack.empty();
    }
```