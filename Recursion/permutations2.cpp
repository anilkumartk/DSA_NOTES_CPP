/*
LeetCode - 47.Permutations 2

Approach - Recursion & Backtracking
TC - O(N * N!)
SC - O(N!)



In for loop we don't need to call not take recursion call. for will handle it.
map skips duplicate value recursion. It only calls unique value recursion




*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    map<int,int>mp;
    void solve(int n,vector<int>& dp,vector<int>& nums){
        if(dp.size()==n){
            ans.push_back(dp);   // base case
            return;
        }
        for(auto& [i,co]:mp){
            if(co==0)continue;  // skip
            dp.push_back(i);    //insert to temp array
            mp[i]--;
            solve(n,dp,nums);  //take & recursion call
            dp.pop_back();      //remove from temp array 
            mp[i]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>dp;
        solve(n,dp,nums);
        return ans;
    }
};