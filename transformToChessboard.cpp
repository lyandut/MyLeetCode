//
// Created by liyan on 2019-05-22.
//

#include "MyLeetCode.h"

/*
 * 782. Transform to Chessboard
 * https://leetcode.com/problems/transform-to-chessboard/
 */
static bool isOpposite(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) { return false; }
    for(int i=0; i<A.size(); ++i){
        if(A[i]+B[i] != 1){
            return false;
        }
    }
    return true;
}

static int calculate(vector<int> &A, int countZero, int countOne){
    int zeroStartCount = 0;
    for(int i=0; i<A.size(); ++i){
        if(A[i] == i % 2) { zeroStartCount++; }
    }
    int oneStartCount = A.size() - zeroStartCount;
    if(zeroStartCount % 2){
        return oneStartCount;
    }
    else if(oneStartCount % 2){
        return zeroStartCount;
    }
    else{
        return min(zeroStartCount, oneStartCount);
    }
}

int MyLeetCode::movesToChessboard(vector<vector<int>> &board) {
    int rowLength = board.size(), colLength = board[0].size();
    vector<int> firRow(board[0]);
    vector<int> firCol(colLength);
    for(int i=0; i<rowLength; ++i){
        firCol[i] = board[i][0];
    }
    // check
    for(int i=1; i<rowLength; ++i){
        if(board[i] != firRow && !isOpposite(board[i], firRow)) {
            return -1;
        }
    }
    // Col check
    int rowZero = count(firRow.begin(), firRow.end(), 0);
    int rowOne = rowLength - rowZero;
    if(abs(rowZero-rowOne) > 1) { return -1; }
    // Row check
    int colZero = count(firCol.begin(), firCol.end(), 0);
    int colOne = colLength - colZero;
    if(abs(colZero-colOne) > 1) { return -1; }
    // calculate
    int res = 0;
    res += calculate(firRow, rowZero, rowOne);
    res += calculate(firCol, colZero, colOne);
    return res / 2;
}
