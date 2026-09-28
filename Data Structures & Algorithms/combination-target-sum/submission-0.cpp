class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums,int i, int target,vector<int>&curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(i==nums.size()|| target<0)return;

        curr.push_back(nums[i]);
        solve(nums,i,target-nums[i],curr);
        curr.pop_back();
        solve(nums,i+1,target,curr);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        solve(nums,0,target,curr);
        return ans;
    }
};
