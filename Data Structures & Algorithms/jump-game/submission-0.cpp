class Solution {
public:
    vector<int>temp;
    bool solve(int i,vector<int>&nums){
        if(i>=nums.size()-1){
            return true;
        }
        if(temp[i]!=-1){
            return temp[i];
        }
        for(int jump=1;jump<=nums[i];jump++){
            if(solve(i+jump,nums)){
                return temp[i]=true;
            }
        }
        return temp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        temp.resize(nums.size(),-1);
        return solve(0,nums);
    }
};
