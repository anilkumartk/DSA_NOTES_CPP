/*
    CSES - 2. Missing Number
    Approach - XOR
    TC - O(N)
    SC - O(1)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int xr=0,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		xr^=i;
	}
	for(int i=1;i<n;i++){
		int a;
		cin>>a;
		xr^=a;
	}
	cout<<xr<<"\n";
}