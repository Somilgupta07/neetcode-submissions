class Solution {
public:
    
    int solve(int i, int j, string &text1, string &text2,
              vector<vector<int>>& dp) {

        if(i == text1.length() || j == text2.length()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(text1[i]==text2[j]){
            return dp[i][j]=1+solve(i+1,j+1,text1,text2,dp);
        }
        int skipFirst=solve(i+1,j,text1,text2,dp);
        int skipSecond=solve(i,j+1,text1,text2,dp);
        return dp[i][j]=max(skipFirst,skipSecond);
              }


    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m,vector<int>(n, -1));

        return solve(0, 0, text1, text2, dp);
    }
};
