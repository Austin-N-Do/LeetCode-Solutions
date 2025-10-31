#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if (solve(board)) return true;
                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number fits
                }
            }
        }
        return true; // board filled successfully
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; ++i) {
            // Check row
            if (board[row][i] == ch) return false;
            // Check column
            if (board[i][col] == ch) return false;
            // Check 3x3 box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == ch) return false;
        }
        return true;
    }
};
