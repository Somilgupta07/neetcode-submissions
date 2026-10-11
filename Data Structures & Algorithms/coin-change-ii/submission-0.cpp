class Solution {
public:
    vector<vector<int>>dp;
    int solve(int amount,int i,vector<int>& coins){
        if(amount==0)return 1;
        if(amount<0||i==coins.size())return 0;
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int take=solve(amount-coins[i],i,coins);
        int skip=solve(amount,i+1,coins);
        return dp[i][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(amount,0,coins);

    }
};
