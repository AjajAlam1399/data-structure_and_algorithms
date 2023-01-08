#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        return validate(board);
    }

    bool validate(vector<vector<char>> &board)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] != '.')
                {
                    if (isValid(i, j, board, board[i][j]) == false)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, vector<vector<char>> &board, char ch)
    {

        for (int i = 0; i < 9; i++)
        {

            if (i != col && board[row][i] == ch)
            {
                return false;
            }
            if (i != row && board[i][col] == ch)
            {
                return false;
            }
            if ((3 * (row / 3) + i / 3) != row && (3 * (col / 3) + i % 3) != col && board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            {
                return false;
            }
        }
        return true;
    }
};