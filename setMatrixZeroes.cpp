//
// Created by liyan on 2019-05-21.
//

#include "MyLeetCode.h"

/*
 * 73. Set Matrix Zeroes
 * https://leetcode.com/problems/set-matrix-zeroes/
 */

void MyLeetCode::setZeroes(vector<vector<int>> &matrix) {
    bool isFirRowZero = false, isFirColZero = false;
    int rowLength = matrix.size(), colLength = matrix[0].size();
    for(int i=0; i<rowLength; ++i){
        if(matrix[i][0] == 0){
            isFirColZero = true;
            break;
        }
    }
    for(int j=0; j<colLength; ++j){
        if(matrix[0][j] == 0){
            isFirRowZero = true;
            break;
        }
    }

    for(int i=1; i<rowLength; ++i){
        for(int j=1; j<colLength; ++j){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i=1; i<rowLength; ++i){
        if(matrix[i][0] == 0){
            for(int j=0; j<colLength; ++j){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j=1; j<colLength; ++j){
        if(matrix[0][j] == 0){
            for(int i=0; i<rowLength; ++i){
                matrix[i][j] = 0;
            }
        }
    }

    if(isFirColZero){
        for(int i=0; i<rowLength; ++i){
            matrix[i][0] = 0;
        }
    }
    if(isFirRowZero){
        for(int j=0; j<colLength; ++j){
            matrix[0][j] = 0;
        }
    }
}
