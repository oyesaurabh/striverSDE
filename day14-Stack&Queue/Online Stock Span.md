[link](https://leetcode.com/problems/online-stock-span/)
# Online Stock Span
```
Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
```
## Solution :: TLE
time : O(N) Space : O(2N)
```cpp
class StockSpanner {
    stack<int> s;
public:
    StockSpanner() {  }
    
    int next(int price) {
        stack<int> temp=s;
        s.push(price);
        int k=1;
        while( !temp.empty() && temp.top() <= price ){
            k++;
            temp.pop();
        }
        return k;
    }
};
```
## Solution :: Best

```cpp
class StockSpanner {
    stack<pair<int,int>> s;
public:
    StockSpanner(){}

    int next(int price) {

        int cnt=1;
        while(!s.empty() && s.top().first <= price){
            cnt+=s.top().second;
            s.pop();
        }
        s.push({price,cnt});
        return cnt;
        
    }
};
```