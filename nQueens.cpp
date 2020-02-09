//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 51. N-Queens
 * https://leetcode.com/problems/n-queens/
 *【专题】回溯、递归
 */

static bool isValid(const vector <string> &board, int row, int col) {
    int leftup = col - 1, rightup = col + 1;
    for (int i = row - 1; i >= 0; --i) {
        if (board[i][col] == 'Q') return false;
        if (leftup >= 0 && board[i][leftup] == 'Q') return false;
        if (rightup < board.size() && board[i][rightup] == 'Q') return false;
        --leftup;
        ++rightup;
    }
    return true;
}

static void dfs(vector <vector<string>> &res, vector <string> &board, int row) {
    if (row == board.size()) {
        res.emplace_back(board);
        return;
    }

    for (int col = 0; col < board.size(); ++col) {
        if (isValid(board, row, col)) {
            board[row][col] = 'Q';
            dfs(res, board, row + 1);
            board[row][col] = '.';
        }
    }
}

vector <vector<string>> MyLeetCode::solveNQueens(int n) {
    vector <vector<string>> res;
    vector <string> board(n, string(n, '.'));
    dfs(res, board, 0);
    return res;
}