[Question link](https://leetcode.com/problems/merge-sorted-array/)
<br>
[Another One](https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/)
# Merge two sorted arrays

## Problem statement

Given two sorted arrays, we need to merge them into a sorted array, when n is the size of the first array, and m is the size of the second array.  
In final output, first array contains first n sorted elements, second array contains last m sorted elements in sorted order.

## Approach 1 (Extra memory)

Time complexity : O(N+M)  
Space complexity : O(N+M)

```cpp
void merge(long long arr1[], long long arr2[], int n, int m)
{
    long long newArr[n+m];
    int i=0, j=0, k=0;
    while(i<n && j<m) {
        if(arr1[i] <= arr2[j])
            newArr[k++] = arr1[i++];
        else
            newArr[k++] = arr2[j++];
    }
    while(i<n) newArr[k++] = arr1[i++];
    while(j<m) newArr[k++] = arr2[j++];
    for(k=0, i=0, j=0; k<n+m; k++) {
        if(k<n) arr1[i++] = newArr[k];
        else arr2[j++] = newArr[k];
    }
}
```

## Approach 2 (Insertion sort)

Time complexity : O(N\*M)  
Space complexity : O(1)

```cpp
void merge(long long arr1[], long long arr2[], int n, int m)
{
    for(int i=0; i<n; i++) {
        if(arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            for(int j=0; j<m-1; j++) {
                if(arr2[j] > arr2[j+1])
                    swap(arr2[j], arr2[j+1]);
                else break;
            }
        }
    }
}
```

## Approach 3 (Two pointer)

Time complexity : O(n + m)  
Space complexity : O(1) (Ignoring space of sorting algo), otherwise O(N+M) due to merge sort

```cpp
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i=n-1, j=0;
    while(i>=0 && j<m) {
        if(arr1[i] > arr2[j])
            swap(arr1[i--], arr2[j++]);
        else
            break;
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
}
```

## Approach 4 (Gap method)

Time complexity : O((N+M)\*log(N+M))  
Space complexity : O(1)

```cpp
    int nextGap(int gap){
        if (gap <= 1)
            return 0;
        return ceil(gap/2.0);
    }
        
    void merge(long long a[], long long b[], int n, int m) {
        
        long long gap=n+m;
        for (gap = nextGap(gap);gap > 0; gap = nextGap(gap)){
            //for Array A
        long long i,j;
        for(i=0;i+gap<n;i++)
            if(a[i]>a[i+gap])
                swap(a[i],a[i+gap]);
            
        //for Array A and  B
        for (j = gap > n ? gap - n : 0;i < n && j < m;i++, j++)
            if (a[i] > b[j])
                swap(a[i], b[j]);
                    
        //for Array B
        for(j=0;j+gap<m;j++)
            if(b[j]>b[j+gap])
                swap(b[j],b[j+gap]);
        }
    }
```