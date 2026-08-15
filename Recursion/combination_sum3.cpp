/*
LeetCode - 216. Combination Sum 3

Approach - Recursion & Backtracking

TC - O(2 ^ 9)
SC - O(k) -> no of valid permutations



if(n<0)return. This invalid case can be included
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int k,int n,vector<int>& dp){
        if(i==10){
            if(n==0 && dp.size()==k){
                ans.push_back(dp);      // base case
            }
            return;
        }
        dp.push_back(i);
        solve(i+1,k,n-i,dp);    //do
        dp.pop_back();
        solve(i+1,k,n,dp);      //undo
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>dp;
        solve(1,k,n,dp);
        return ans;
    }
};
