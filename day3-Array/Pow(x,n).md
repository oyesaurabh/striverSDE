[Question Link](https://leetcode.com/problems/powx-n/)

# Pow(x, n)

## Problem statement
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

>Example 1:
>Input: x = 2.00000, n = 10
>Output: 1024.00000

## Approach 1 ( Naive Approach )
Time Complexity: O(N)
Space Complexity: O(1)

```cpp
double myPow(double x, int n) {
        int k=abs(n);
        double ans=1.0;
        while(k--)
            ans*=x;
        if(n<0)ans=1.0/ans;
        return ans;
    }
```

## Approach 2 ( Using Binary Exponentiation )
Time Complexity: O(log n)
Space Complexity: O(1)

```cpp
double myPow(double x, int n) {
        //recursion
         double ans=1.0;
         int sign=n;
         if(n==0 || x==1)return 1;      // 1^x=1 && x^0=1
         else{
            if(n<0)
                 n=abs(n);
             //odd
             if(n&1)
                 ans=x*pow(x,n-1);
             //even
             else
                 ans=ans*pow(x*x,n/2);
            
         }
         if(sign<0)return 1.0/ans; 
         return ans;
    }
             OR
double myPow(double x,int n){
        //iteration
        double ans=1.0;
        long long nn=n;
        if(n==0 || x==1)return 1.0;
        n=abs(n);
        while(nn){
            if(n&1)
                ans=ans*x,nn-=1;
            else
                x=x*x,nn/=2;

        }
        if(n<0)
            ans=1.0/ans;
        return ans;
}

```
