/*

LeetCode - 52. N-Queens 1

Approach - Recursion & Backtracking
TC - O(N * N!)
SC - O(N ^ 2)





*/
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
     bool isSafe(vector<string>& boa,int row,int col,int n){
        //top
        for(int i=row-1;i>=0;i--){
            if(boa[i][col]=='Q')return false;
        }
        //left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(boa[i][j]=='Q')return false;
        }
        //right diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(boa[i][j]=='Q')return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& res,vector<string>& boa,int row,int n){
        if(row==n){
            res.push_back(boa);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(boa,row,col,n)){
                boa[row][col]='Q';  //DO
                solve(res,boa,row+1,n);
                boa[row][col]='.';  //UNDO
            }
        }
    }
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string>boa(n,s);
        vector<vector<string>>res;
        solve(res,boa,0,n);
        return res.size();
    }
};