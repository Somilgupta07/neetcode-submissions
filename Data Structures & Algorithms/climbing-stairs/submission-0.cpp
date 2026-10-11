class Solution {
public:
    vector<int>dp;
    int solve(int n,int i){
        if(i==n)return 1;
        if(i>n)return 0;

        if(dp[i]!=-1)return dp[i];

        int climb1=solve(n,i+1);
        int climb2=solve(n,i+2);
        return dp[i]=climb1+climb2;
    }
    int climbStairs(int n) {
        dp.assign(n,-1);
        return solve(n,0);
    }
};
