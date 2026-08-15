/*
LeetCode - 40.Combination Sum 2

Approach - Recursion & Backtracking
TC - O(n*logn + k∗2^n) ->k-no of valid answers
SC - O(n+k∗n)





*/



#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int n,vector<int>& dp,vector<int>& nums,int tar){
        
        if(tar==0){
            ans.push_back(dp);   // base case 
             return;
        }
            
        if(tar<0)return;  //invalid case prune search or return
       
        for(int ind=i;ind<n;ind++){
            if(ind>i && nums[ind]==nums[ind-1])continue;
            if(nums[ind]>tar)break;                 //invalid case exit from loop
            dp.push_back(nums[ind]);                //insert to temp array
            solve(ind+1,n,dp,nums,tar-nums[ind]);  // take
            dp.pop_back();                          //remove from temp array
        }
        
        //solve(i+1,n,dp,nums,tar);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>dp;
        sort(candidates.begin(),candidates.end());  // sorting O(n*logn)
        solve(0,n,dp,candidates,target);
        return ans;
    }
};