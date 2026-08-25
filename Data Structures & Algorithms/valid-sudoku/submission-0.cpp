class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>cols(9);
        vector<unordered_set<char>>boxes(9);
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char ch=board[r][c];
                if(ch=='.')continue;

                int box=(r/3)*3+(c/3);
                if(rows[r].count(ch) ||cols[c].count(ch)|| boxes[box].count(ch)){
                    return false;
                }
                rows[r].insert(ch);
                cols[c].insert(ch);
                boxes[box].insert(ch);
            }
        }
        return true;

    }
};
