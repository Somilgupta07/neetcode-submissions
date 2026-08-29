class Solution {
public:
    vector<int>dp;
    int solve(int i,vector<int>& nums){
        if(i>=nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int jump=1;jump<=nums[i];jump++){
            int next=i+jump;
            if(next<nums.size()){
                int result=solve(next,nums);
                if(result!=INT_MAX){
                    ans=min(ans,1+result);
                }

            }
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(0,nums);
    }
};
