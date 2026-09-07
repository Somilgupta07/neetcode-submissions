class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap){
        int day=1;
        int sum=0;
        for(int w: weights){
            if(sum+w>cap){
                day++;
                sum=0;
            }
            sum+=w;
        }
        return day<=days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        for(int w: weights){
            low=max(w,low);
            high+=w;
        }

        while(low<high){
            int mid=low+(high-low)/2;
            if(canShip(weights,days,mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};