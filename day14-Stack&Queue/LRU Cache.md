[Link](https://leetcode.com/problems/lru-cache/)
# LRU cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
```
Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```
## Solution 
Time Complexity:O(N)<br>
Space Complexity:O(1)
```cpp
class LRUCache {
    class node{
        public:
        int value,key;
        node *pre,*next;
        node(int key,int value){
            this->value=value;
            this->key=key;
        }
    };
public:
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int, node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->pre=head;
    }
    void add_(node *newnode){
        newnode->next=head->next;
        newnode->pre=head;
        head->next=newnode;
        newnode->next->pre=newnode;
    }
    void delete_(node *n){
        node *delete_next=n->next;
        node *delete_pre=n->pre;
        delete_next->pre=delete_pre;
        delete_pre->next=delete_next;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){ //exist
            auto node = mp[key];
            // mp.erase(key);
            // int result=node->value;
            delete_(node);
            add_(node);
            // mp[key]=head->next;
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node *temp=mp[key];
            delete_(temp);
            mp.erase(key);
        }
        if(cap==mp.size()){
            mp.erase(tail->pre->key);
            delete_(tail->pre);
        }
        add_(new node(key,value));
        mp[key]=head->next;
    }
};

```