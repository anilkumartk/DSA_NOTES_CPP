/*

CSES - Tower of Hanoi
TC - O(2 ^ n)
SC - O(2 ^ n)

Disc goes from -> aux and then aux -> to


*/

#include<bits/stdc++.h>
using namespace std;
void solve(int n,int from,int to,int aux){
    if(n==1){
        cout<<from<<" "<<to<<"\n";
        return;
    }
    solve(n-1,from,aux,to);
    cout<<from<<" "<<to<<"\n";
    solve(n-1,aux,to,from);
}
int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    solve(n,1,3,2);
}