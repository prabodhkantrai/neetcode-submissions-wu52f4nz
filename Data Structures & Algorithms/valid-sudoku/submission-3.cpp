class Solution {
public:
    bool checkBoard(vector<vector<char>>& board, int x){
        // Check Column
        unordered_set<int> s;
        for (int i = 0; i < 9 ; i++){
            if (board[i][x] == '.') continue;
            if (!(s.insert(board[i][x]).second)) return false;
        }

        s.clear();

        // Check Row
        for (int i = 0; i < 9 ; i++){
            cout<<board[x][i];
            if (board[x][i] == '.') continue;
            if (!(s.insert(board[x][i]).second)) return false;
        }
        return true;
    }

    bool checkBox(vector<vector<char>>& board, int x, int y){
        unordered_set<int> s;
        for (int i = (x / 3)*3; i < (x/3)*3 + 3; i++) {
            for (int j = (y / 3)*3; j < (y/3)*3 + 3; j++) {
                if (board[i][j] == '.') continue;
                if(!(s.insert(board[i][j]).second)) return false;
            }
        }        
        
        return true;
    } 

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if(!checkBoard(board, i)) return false;
        }

        for(int i = 1; i < 9 ; i=i+3){
            for (int j = 1; j < 8; j=j+3){
                if (!checkBox(board, i, j)) return false;
            }
        }
        return true;
    }
};
