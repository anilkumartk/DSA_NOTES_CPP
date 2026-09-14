/*
GFG - Merge Sort
Approach - Recursion, Divide & Conquer 
TC - O(n * log n)
SC - O(n)


Divide the array half at every step and then merge them.
*/


#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int low,int mid,int high){
    vector<int>temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(vector<int>& arr,int low,int high){
    if(low>=high)return;        //base case or invalid case to return   
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}
int main(){
    vector<int>arr={4,2,1,3,5,9,6,7};
    mergeSort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}