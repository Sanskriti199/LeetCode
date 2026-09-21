class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},   {1, 1}
        };

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                int liveNeighbors = 0;

                for (auto& direction : directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];

                    if (newRow >= 0 && newRow < rows &&
                        newCol >= 0 && newCol < cols) {

                        if (board[newRow][newCol] == 1 ||
                            board[newRow][newCol] == 2) {
                            liveNeighbors++;
                        }
                    }
                }

                if (board[row][col] == 1 &&
                    (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = 2;
                }

                if (board[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 3;
                }
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (board[row][col] == 2)
                    board[row][col] = 0;

                else if (board[row][col] == 3)
                    board[row][col] = 1;
            }
        }
    }
};