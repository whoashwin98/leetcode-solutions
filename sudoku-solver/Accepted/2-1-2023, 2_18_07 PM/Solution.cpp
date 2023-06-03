// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
bool isSafe(vector<vector<char>> &board, int r, int c, char ch)
{
    for (int i = 0; i < 9; i++)
    {
        // check for same column
        if (board[i][c] == ch)
            return false;
        // check for same row
        if (board[r][i] == ch)
            return false;
        // check if in the current element's 3x3 grid for same number
        // logic is : row or col / 3 = {0,1,2}
        // {0,1,2} * 3 = {0,3,6} - takes to the starting rows for grids
        // now we add i/3 to row and i%3 to column, since i/3 changes slower and i%3 fluctuates like column value
        if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
            return false;
    }
    return true;
}

// function that will check for each empty space whether a particular number can be filled or not
bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    // if it is a safe square for that particular character
                    if (isSafe(board, i, j, c))
                    {
                        // place it onto the board
                        board[i][j] = c;
                        // if placing that character leads to a solution, then return true
                        if (solve(board) == true)
                            return true;
                        // otherwise backtrack to find another solution
                        else
                            board[i][j] = '.';
                    }
                }

                // if a particular cell cannot be filled with any element, that means we need to backtrack
                return false;
            }
        }
    }

    // control reaches here if the loop is completed successfully
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

};