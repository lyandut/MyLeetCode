//
// Created by liyan on 2019-05-20.
//

#include "MyLeetCode.h"

/*
 * 849. Maximize Distance to Closest Person
 * https://leetcode.com/problems/maximize-distance-to-closest-person/
 *【专题】Array
 */
int MyLeetCode::maxDistToClosest(vector<int> &seats) {
    int i;
    int frontIndex = -1, maxDis = 0;
    int headDis = 0, tailDis = 0;
    for(i=0; i<seats.size(); i++){
        if(seats[i] && frontIndex == -1){
            headDis = i;
        }
        else if(seats[i]){
            maxDis = maxDis > (i - frontIndex) ? maxDis : (i - frontIndex);
        }
        frontIndex = i;
    }
    tailDis = i - 1 - frontIndex;
    return max(max(headDis, tailDis), maxDis / 2);
}
