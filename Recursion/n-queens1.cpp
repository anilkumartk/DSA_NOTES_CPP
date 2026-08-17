/*

LeetCode - 51. N-Queens 1

Approach - Recursion & Backtracking
TC - O(N * N!)
SC - O(N ^ 2)





*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe(int row,int col,int n,vector<string>& boa){
        //top
        for(int i=row-1;i>=0;i--){
            if(boa[i][col]=='Q'){
                return false;
            }
        }
        //left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(boa[i][j]=='Q'){
                return false;
            }
        }
        //right diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(boa[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int row,int n,vector<string>& boa){
        if(row==n){
            ans.push_back(boa);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row,col,n,boa)){
                boa[row][col]='Q';      //Do
                solve(row+1,n,boa);     //recursion call
                boa[row][col]='.';      //Undo
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>boa(n,s);
        solve(0,n,boa);
        return ans;
    }
};