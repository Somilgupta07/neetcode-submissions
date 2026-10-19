class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate=-1;
        int cnt=0;
        // find the candidate
        for(int num: nums){
            if(cnt==0){
                candidate=num;
                cnt++;
            }else if(candidate==num){
                cnt++;
            }else{
                cnt--;
            }
        }
        // verify the candidate
        cnt=0;
        for(int num:nums){
            if(num==candidate){
                cnt++;
            }
        }

        if(cnt>n/2){
            return candidate;
        }else{
            return -1;
        }
    }
};