class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto&pre: prerequisites){
            int course=pre[0];
            int prerequisite=pre[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int course=q.front();
            q.pop();
            cnt++;

            for(int nextCourse: graph[course]){
                indegree[nextCourse]--;
                if(indegree[nextCourse]==0){
                    q.push(nextCourse);
                }
            }
        }
        return cnt==numCourses;

    }
};
