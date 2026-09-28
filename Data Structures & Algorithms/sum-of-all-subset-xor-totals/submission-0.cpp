class Solution {
public:
    int ans=0;
    void solve(vector<int>& nums,int index,int xorValue){
        if(index==nums.size()){
        ans+=xorValue;
        return;
        }

        solve(nums,index+1,xorValue);
        solve(nums,index+1,nums[index]^xorValue);

    }
    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return ans;
    }
};