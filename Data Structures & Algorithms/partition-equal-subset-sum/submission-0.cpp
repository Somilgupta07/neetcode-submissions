class Solution {
public:
     bool dp(int i, int target,
            vector<int>& nums,
            vector<vector<int>>& memo) {

                if(target==0)return true;
                if(i==nums.size())return false;

                if(memo[i][target]!=-1)return memo[i][target];
                bool notTake=dp(i+1,target,nums,memo);
                bool take=false;
                if(nums[i]<=target){
                    take=dp(i+1,target-nums[i],nums,memo);
                }
                return memo[i][target]=take|| notTake;







            }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums)
            sum+=x;

        if(sum%2!=0)return false;
        int target=sum/2;
        vector<vector<int>>memo(nums.size(),vector<int>(target+1,-1));

        return dp(0,target,nums,memo);

    }
};
