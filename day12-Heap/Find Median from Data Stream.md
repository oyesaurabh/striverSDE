[Link](https://leetcode.com/problems/find-median-from-data-stream/)
# Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.<br>
For example, for arr = [2,3,4], the median is 3.<br>
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.<br>
***Example 1:***
```
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```
## Naive
Time O(N*NlogN)<br>
Space O(N)
```cpp
class MedianFinder {
    vector<int> t;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        t.push_back(num);
    }
    
    double findMedian() {
        int n=t.size();
        sort(t.begin(), t.end());
        if(n&1)
            return t[n/2];
        return (t[n/2]+t[ (n/2)-1])/2.0;
    }
};
```
## Min_heap and Max_heap
TIme : O(LogN)<br>
Space : O(N)
```cpp
class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(max_heap.empty() && min_heap.empty()){
            max_heap.push(num);
            return;
        }
        if(num > max_heap.top()){
            min_heap.push(num);
            //balancing
            if(min_heap.size()>max_heap.size()){
                int t=min_heap.top();
                min_heap.pop();
                max_heap.push(t);
            }
        }else{
            max_heap.push(num);
            //balancing
            if(max_heap.size()>min_heap.size()+1){
                int t=max_heap.top();
                max_heap.pop();
                min_heap.push(t);
            }            
        }
        
    }
    
    double findMedian() {
        int sum=max_heap.size()+min_heap.size();
        if(sum%2)
            return max_heap.top();
        return (max_heap.top()+min_heap.top())/2.0;
    }
};
```