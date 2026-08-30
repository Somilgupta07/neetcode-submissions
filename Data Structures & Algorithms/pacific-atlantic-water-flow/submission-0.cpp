class Solution {
public:
    int rows,cols;
    vector<vector<int>>dirs{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int row,int col,vector<vector<int>>& heights,vector<vector<bool>>& visited){
        visited[row][col]=true;
        for(auto &dir: dirs){
            int newRow=row+dir[0];
            int newCol=col+dir[1];

            if(newRow<0 || newRow>=rows|| newCol<0 || newCol>=cols){
                continue;
            }
            if(visited[newRow][newCol]){
                continue;
            }
            if(heights[newRow][newCol]<heights[row][col]){
                continue;
            }
            dfs(newRow,newCol,heights,visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        vector<vector<bool>>pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>>atlantic(rows,vector<bool>(cols,false));

        for(int col=0;col<cols;col++){
            dfs(0,col,heights,pacific);
        }
        for(int row=0;row<rows;row++){
            dfs(row,0,heights,pacific);
        }
        for(int col=0;col<cols;col++){
            dfs(rows-1,col,heights,atlantic);
        }
        for(int row=0;row<rows;row++){
            dfs(row,cols-1,heights,atlantic);
        }
        vector<vector<int>>res;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(pacific[row][col]&& atlantic[row][col]){
                    res.push_back({row,col});
                }
            }
        }
        return res;
    }
};
