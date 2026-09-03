class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left = 0;
        int currSum = 0;
        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            while (currSum >= target) {
                minLen = min(minLen, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};