/*
LeetCode - 37.Combination Sum

Approach - Recursion & Backtracking
TC - O(9 ^ n) -> n is number of empty cells
SC - O(n)




*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isvalid(vector<vector<char>>& boa,int r,int c,char ch){
        for(int i=0;i<9;i++){
            if(boa[r][i]==ch)return false;  //row check
            if(boa[i][c]==ch)return false;  //column check
            if(boa[3*(r/3)+i/3][3*(c/3)+i%3]==ch)return false; //3 X 3 box check
        }
        return true;
    }
    bool solve(vector<vector<char>>& boa){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(boa[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(boa,i,j,c)){
                            boa[i][j]=c;        //DO
                            if(solve(boa)){
                                return true;    //answer found
                            }else{
                                boa[i][j]='.';  //UNDO
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};