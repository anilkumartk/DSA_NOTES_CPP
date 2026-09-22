/*

TC - O(N + Q * log N)
SC - O(N)

*/
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int seg[4*N];
void build(int node,int l,int r){
    if(l==r){
        seg[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    seg[node]=max(seg[2*node],seg[2*node + 1]);
}
void update(int node,int l,int r,int idx,int val){
        if(l==r){
            a[idx]=val;
            seg[node]=val;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)
            update(2*node,l,mid,idx,val);
        else
            update(2*node+1,mid+1,r,idx,val);
        seg[node]=max(seg[2*node],seg[2*node+1]);
}
int query(int node,int l,int r,int ql,int qr){
    if(r<ql || l>qr){
        return INT_MIN;
    }
    if(ql<=l && r<=qr){
        return seg[node];
    }
    int mid=(l+r)/2;
    return max(query(2*node,l,mid,ql,qr),
                query(2*node+1,mid+1,r,ql,qr));
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    
}