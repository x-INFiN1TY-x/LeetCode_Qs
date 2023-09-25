class Solution
{
    private:
        bool solve(vector<vector < char>> &board)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        for (char k = '1'; k <= '9'; k++)
                        {
                            if (ispossible(board, i, j, k))
                            {
                                board[i][j] = k;
                                if (solve(board))
                                {
                                    return true;
                                }
                                board[i][j] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
    bool ispossible(vector<vector < char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == ch && i != row)
            {
                return false;
            }
            if (board[row][i] == ch && i != col)
            {
                return false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((board[3 *(row / 3) + i % 3][3 *(col / 3) + j % 3] == ch) && (3 *(row / 3) + i % 3 != row) && (3 *(col / 3) + j % 3 != col))
                {
                    return false;
                }
            }
        }
        return true;
    }
    public:
        void solveSudoku(vector<vector < char>> &board)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            solve(board);
        }
};