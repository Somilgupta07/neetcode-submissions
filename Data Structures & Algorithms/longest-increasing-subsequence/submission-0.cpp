class Solution {
public:
    int dp(int i, int prev,
           vector<int>& nums,
           vector<vector<int>>& memo) {

            if(i==nums.size())return 0;
            if(memo[i][prev+1]!=-1)return memo[i][prev+1];
            int notTake=dp(i+1,prev,nums,memo);
            int take=0;
            if(prev==-1 || nums[i]>nums[prev]){
                take=1+dp(i+1,i,nums,memo);
            }
            return memo[i][prev+1]=max(take,notTake);
           }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>memo(n,vector<int>(n+1,-1));
        return dp(0,-1,nums,memo);

    }
};
