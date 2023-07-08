#include <bits/stdc++.h> 

long long merge(long long *arr, int start , int mid, int end){
    vector<int> ds;
    long long count = 0;
    int i = start, j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            ds.push_back(arr[i]);
            i++;
        }
        else{
            count += (mid-i+1);
            ds.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        ds.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        ds.push_back(arr[j]);
        j++;
    }
    for(int k = start; k<=end; k++){
        arr[k] = ds[k-start];
    }
    return count;
}

long long mergeSort(long long *arr, int start, int end){

    if(start >= end) return 0;
    long long count = 0;
    int mid = (start+end)/2;
    count += mergeSort(arr,start,mid);
    count += mergeSort(arr,mid+1,end);
    count += merge(arr,start,mid,end);
    return count;
}


long long getInversions(long long *arr, int n){
    // Write your code here.
    /*
    Brute Approach-
    ->We can just run a nested loop and for each element we can find how many elements are smaller than
        it on its right side.
    ->TC-O(N^2) and SC-O(1)
    Modified Merge Sort approach
    ->We can just modiify the merge sort algorithm and count the number of inversion while merging the
        array if the element of second array is smaller than the element of first array.
    -> TC-O(Nlog(N)) and SC-O(N);
    -> SC can futher be optimised using the merging the arrays without extra space technique
    */
    return mergeSort(arr,0,n-1);
}