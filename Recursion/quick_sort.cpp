/*
GFG - Quick Sort
Approach - Recursion 
TC - O(n * log n)
SC - O(n)

Divide array based on pivot index. In partition method swap every small element and atlast swap arr[high],arr[pi].
At every call patition element will go its correct position in sorted order.
*/

#include<bits/stdc++.h>
using namespace std;
int parti(vector<int>& arr,int low,int high){
    int pivot=arr[high];        //assume pivot element
    int pi=low;                 //start from low means divided array starting point
    for(int i=low;i<high;i++){
        if(arr[i]<=pivot){          //we want left side small elements
            swap(arr[i],arr[pi]);   //swap every small element
            pi++;
        }
    }
    swap(arr[pi],arr[high]);        //last and pivot element swaping
    return pi;                      //pivot index
}
void quickSort(vector<int>& arr,int low,int high){
    if(low>=high)return;        //base case or invalid case to return
    int pi=parti(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}
int main(){
    vector<int>arr={4,2,1,3,5,9,6,7};
    quickSort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}