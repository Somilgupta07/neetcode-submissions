class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
            // removing the indices which are not in window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // remove smaller elements from the back
            while(!dq.empty() &&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            // store index in deque
            dq.push_back(i);

            // our window is ready
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }

        }

        return ans;
    }
};
