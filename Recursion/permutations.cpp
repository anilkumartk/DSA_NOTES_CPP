/*
LeetCode - 46.Permutations

Approach - Recursion & Backtracking
TC - O(N * N!)
SC - O(N!)



In for loop we don't need to call not take recursion call. for will handle it.
*/


#incluse<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void solve(int n,vector<int>& nums,vector<int>& dp,vector<bool>& vis){
    
         if(dp.size()==n){
            ans.push_back(dp);  //base case
            return;
         }
        else{
            for(int i=0;i<n;i++){
                if(vis[i])continue;
                vis[i]=true;
                dp.push_back(nums[i]);      // take
                solve(n,nums,dp,vis);       //recursion call
                vis[i]=false;
                dp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool>vis(n,false);
        vector<int>dp;
        solve(n,nums,dp,vis);
        return ans;
    }
};