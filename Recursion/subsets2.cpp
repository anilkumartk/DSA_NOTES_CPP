/*

LeetCode - 90.Subsets 2

Approach - Recursion & Backtracking
TC - O(n*logn + k∗2^n) ->k-no of valid answers
SC - O(n+k∗n)


If we are using for loop inside recursion then we can just add temp array to ans array. No need to check ind==n condition


*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    void solve(int ind,int n,vector<int>& dp,vector<int>& nums){
        
        ans.push_back(dp);
           
       
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1])continue;  //skip duplicates
            dp.push_back(nums[i]);      //insert to temp array
            solve(i+1,n,dp,nums);   // take
            dp.pop_back();          //remove from temp array
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp;
        solve(0,n,dp,nums);
        return ans;
    }
};