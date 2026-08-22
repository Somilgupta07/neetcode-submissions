class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>qs;
        for(int i=0;i<queries.size();i++){
            qs.push_back({queries[i],i});
        }
        sort(qs.begin(),qs.end());
        int i=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>ans(queries.size(),-1);
        for(auto q: qs){
            int query=q[0];
            int index=q[1];
            while(i<intervals.size() && intervals[i][0]<=query){
                int left=intervals[i][0];
                int right=intervals[i][1];
                int length=right-left+1;
                pq.push({length,right});
                i++;
            }
            while(!pq.empty() && pq.top()[1]<query){
                pq.pop();
            }
            if(!pq.empty()){
                ans[index]=pq.top()[0];
            }
        }
        return ans;
    }
};
