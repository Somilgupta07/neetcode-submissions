class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int target,
              vector<vector<int>>& dp) {
                if(i==nums.size()){
                    if(sum==target)
                        return 1;
                    else
                    return 0;
                }
                if(dp[i][sum+1000]!=-1){
                    return dp[i][sum+1000];
                }
                int add=solve(i+1,sum+nums[i],nums,target,dp);
                int subtract=solve(i+1,sum-nums[i],nums,target,dp);
                return dp[i][sum+1000]=add+subtract;
              }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return solve(0,0,nums,target,dp);
    }
};
