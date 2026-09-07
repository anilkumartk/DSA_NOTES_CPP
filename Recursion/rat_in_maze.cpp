/*
GeekForGeeks - Rat in a Maze

Approach - Recursion & Backtracking
TC - O(4^(n^2))
SC - O(n ^ 2)



*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  vector<string>ans;
  void solve(int i,int j,int n,int m,vector<vector<int>>& maze,string s){
      if(i==n-1 && j==m-1){
          ans.push_back(s);
          return;
      }
      if(maze[i][j]==0)return;
      if(i+1<n && maze[i+1][j]==1){
          maze[i][j]=0;
          solve(i+1,j,n,m,maze,s+'D');
          maze[i][j]=1;
      }
      if(i-1>=0 && maze[i-1][j]==1){
          maze[i][j]=0;
          solve(i-1,j,n,m,maze,s+'U');
          maze[i][j]=1;
          
      }
      if(j+1<m && maze[i][j+1]==1){
          maze[i][j]=0;
          solve(i,j+1,n,m,maze,s+'R');
          maze[i][j]=1;
      }
      if(j-1>=0 && maze[i][j-1]==1){
          maze[i][j]=0;
          solve(i,j-1,n,m,maze,s+'L');
          maze[i][j]=1;
      }
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size(),m=maze[0].size();
        if(maze[0][0]==0 ||maze[n-1][m-1]==0){
            return ans;
        }
        solve(0,0,n,m,maze,"");
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};