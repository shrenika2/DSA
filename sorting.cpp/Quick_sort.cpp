#include <iostream>
#include<vector>
using namespace std ;

int partition(vector<int>&arr , int low , int high){
    int pivote=arr[low];
    int i=low;
    int j=high;
    while (arr[i] <=pivote && i<=high-1){
        i++;
    }
    while (arr[j]>pivote && j>=low+1){
        j++;
    }
    while (i<j){
        swap(arr[i] , arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>&arr , int low , int high){
    if (low<high){
        int pIndex=partition(arr , low , high);
        qs(arr , low , pIndex-1);
        qs(arr , pIndex+1 , high);
    }
}

vector<int>quickSort(vector<int>arr){
    qs(arr , 0, arr.size()-1);
    return arr;
}
