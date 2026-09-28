class Solution {
public:
    int solve(int i,vector<int>& cost,vector<int>&dp){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int oneStep=solve(i+1,cost,dp);
        int twoStep=solve(i+2,cost,dp);
        dp[i]=cost[i]+min(oneStep,twoStep);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};
