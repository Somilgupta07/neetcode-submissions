class Solution {
public:
    vector<vector<int>>res;
    vector<int>curr;
    void solve(vector<int>&nums,int i){
        if(i==nums.size()){
            res.push_back(curr);
            return;
        }
        //take
        curr.push_back(nums[i]);
        solve(nums,i+1);
        curr.pop_back();
        //skip
        solve(nums,i+1);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return res;
    }
};
