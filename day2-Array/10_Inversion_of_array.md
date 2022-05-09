[Question Link](https://www.geeksforgeeks.org/counting-inversions/)
<br>
[Another one](https://leetcode.com/problems/global-and-local-inversions/discuss/242101/Count-inversions)
# Inversion of array

## Problem statement

Given an array of integers. Find the Inversion Count in the array. 

**Inversion Count**: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
> Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

## Approach 1 (Brute force)

Time complexity : O(N^2)  
Space complexity : O(1)

```cpp
long long int inversionCount(long long arr[], long long N) {
    long long i, j, c=0;
    for(i=0; i<N; i++)
        for(j=i+1; j<N; j++)
            if(arr[i]>arr[j])
                c++;
    return c;
}
```

## Approach 2 (Merge sort)

Time complexity : O(N*long(N))  
Space complexity : O(N)

```cpp
long long merge(long long arr[],long long temp[],long long left,long long mid,long long right){
    long long inv_count=0;
    long long i = left;
    long long j = mid;
    long long k = left;
    while((i <= mid-1) && (j <= right))
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        
        else{
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long merge_Sort(long long arr[],long long temp[],long long left,long long right){
    long long mid,inv_count = 0;
    if(right > left){
        mid = (left + right)>>1;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
long long int inversionCount(long long arr[], long long N) {
    long long temp[N];
    return merge_Sort(arr,temp,0,N-1);
    
}
```