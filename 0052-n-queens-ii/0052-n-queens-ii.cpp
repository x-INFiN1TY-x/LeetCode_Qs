class Solution
{
    public:
        void solve(int col, vector<string> &board, int &ans, vector< int > &leftrow, vector< int > &upperDiagonal, vector< int > &lowerDiagonal, int n)
        {
            if (col == n){
                ans++; return ; }
            for (int row = 0; row < n; row++)
            {
                if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
                {
                    board[row][col] = 'Q';
                    leftrow[row]++;
                    lowerDiagonal[row + col]++;
                    upperDiagonal[n - 1 + col - row]++;
                    solve(col +1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
                    board[row][col] = '.';
                    leftrow[row]--;
                    lowerDiagonal[row + col]--;
                    upperDiagonal[n - 1 + col - row]--;
                }
            }
        }

    public:
        int totalNQueens(int n)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            int ans = 0;
            for (int i = 0; i < 1; i++)
            {
                string s(n, '.');
                vector<string> board(n, s);

                vector<int> leftrow(n, 0), upperDiagonal(2 *n - 1, 0), lowerDiagonal(2 *n - 1, 0);
                solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
            }
            return ans;
        }
};