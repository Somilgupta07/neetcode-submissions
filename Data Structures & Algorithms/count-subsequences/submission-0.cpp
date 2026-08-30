class Solution {
public:
    long long solve(int i,int j,string &s,string &t,vector<vector<long long>> &dp){
        if(j==t.length())return 1;
        if(i==s.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            long long take=solve(i+1,j+1,s,t,dp);
            long long skip=solve(i+1,j,s,t,dp);
            return dp[i][j]=take+skip;
        }
        return dp[i][j]=solve(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
        return solve(0,0,s,t,dp);
    }
};
