class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd=nums[0];
        int minEnd=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(minEnd,maxEnd);
            }

            maxEnd=max(maxEnd*nums[i],nums[i]);
            minEnd=min(minEnd*nums[i],nums[i]);

            ans=max(ans,maxEnd);

        }
        return ans;
    }
};
