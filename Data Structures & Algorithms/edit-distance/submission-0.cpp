class Solution {
public: 
int m,n;
 int solve(int i,int j,string &word1,string &word2,vector<vector<int>>&dp){
        if(i==m){
            return n-j;
        }
        if(j==n){
            return m-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(i+1,j+1,word1,word2,dp);
        }else{
            int insertC=1+solve(i,j+1,word1,word2,dp);
            int deleteC=1+solve(i+1,j,word1,word2,dp);
            int replaceC=1+solve(i+1,j+1,word1,word2,dp);
            return dp[i][j]=min({insertC,deleteC,replaceC});

        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        m=word1.length();
        n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};
