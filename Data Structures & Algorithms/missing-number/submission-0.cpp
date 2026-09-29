class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        //xor of all numbers from 0 to n
        for(int i=0;i<=n;i++){
            ans^=i;
        }

        // now xor the nums one
        for(int i=0;i<n;i++){
            ans^=nums[i];
        }
        return ans;

    }
};
