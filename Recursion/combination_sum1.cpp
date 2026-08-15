/*
LeetCode - 39.Combination Sum

Approach - Recursion & Backtracking
TC - O(2 ^ n)
SC - O(target/min_element)





*/



#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int n,vector<int>& nums,vector<int>& dp,int tar){
        if(i==n){
            if(0==tar){
                ans.push_back(dp);      //base case
                
            }
           return;
        }
        if(tar<0)return; // inavalid state return
        
        dp.push_back(nums[i]);
        solve(i,n,nums,dp,tar-nums[i]); //take
        dp.pop_back();
        
        solve(i+1,n,nums,dp,tar);  //not take
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp;
        solve(0,n,nums,dp,target);
        return ans;
    }
};