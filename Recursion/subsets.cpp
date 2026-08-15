/*
LeetCode - 78.Subsets

Approach - Recursion & Backtracking
TC - O(2 ^ n)
SC - O(N)





*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int n,vector<int>& dp,vector<int>& nums){
        if(i==n){
            ans.push_back(dp);   //base case
            return;
        }
        dp.push_back(nums[i]);
        solve(i+1,n,dp,nums);  //take
        dp.pop_back();
        solve(i+1,n,dp,nums);   //not take
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp;
        solve(0,n,dp,nums);
        return ans;
    }
};