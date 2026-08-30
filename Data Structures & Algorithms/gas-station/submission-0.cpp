class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank=0;
        int totalGas=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            totalGas+=diff;
            tank+=diff;


            if(tank<0){
                start=i+1;
                tank=0;
            }
        }
        if(totalGas<0)return -1;
        return start;
    }
};
