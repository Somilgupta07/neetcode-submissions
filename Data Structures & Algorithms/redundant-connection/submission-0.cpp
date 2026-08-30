class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x){return x;}

        return parent[x]=find(parent[x]);
    }

    bool unite(int a ,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)return false;

        parent[pb]=pa;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto& edge: edges){
            int a=edge[0];
            int b=edge[1];

            if(!unite(a,b)){
                return {a,b};
            }
        }
        return {};
    }
};
