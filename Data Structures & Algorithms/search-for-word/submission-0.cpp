class Solution {
public:
bool solve(vector<vector<char>>& board, string word,
               int row, int col, int i) {

                if(i==word.size())return true;

                if(row<0 || col<0|| row>=board.size()||col>=board[0].size()){
                    return false;
                }
                if(board[row][col]!=word[i]){
                    return false;
                }
                char temp=board[row][col];
                board[row][col]='#';

                bool found=
                solve(board,word,row+1,col,i+1)||
                solve(board,word,row-1,col,i+1)||
                solve(board,word,row,col+1,i+1)||
                solve(board,word,row,col-1,i+1);

                board[row][col]=temp;
                return found;

               }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
