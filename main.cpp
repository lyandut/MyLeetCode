#include <iostream>
#include <vector>
#include "MyLeetCode.h"

using namespace std;

int main() {

    MyLeetCode myLeetCode;

//    myLeetCode.book(1, 3);
//    cout << get<2>(myLeetCode.startEndInterval{0});

//    vector<int> A = {2,4,7,8,9,10,14,15,18,23,32,50};
//    cout << myLeetCode.lenLongestFibSubseq(A);

//    vector<int> A = {2,1,2,4,2,2}, B={5,2,6,2,3,2};
//    cout << myLeetCode.minDominoRotations(A, B);

//    vector<int> A = {14,4,5,14,13,14,10,17,2,12,2,14,7,13,14,13,4,16,4,10};
//    myLeetCode.minIncrementForUnique(A);

//    vector<vector<int>> A = {{1,1,0}, {0,0,1}, {0,0,1}};
//    cout << myLeetCode.movesToChessboard(A);

//    vector<vector<int>> A = {{2},{3,4},{6,5,7},{4,1,8,3}};
//    cout << myLeetCode.minimumTotal(A);

//    vector<vector<int>> obstacles{{5, 5}, {9, 4}, {9, 7}, {6, 4}, {7, 0}, {9, 5}, {10, 7}, {1, 1}, {7, 5}};
//    myLeetCode.robot("RRU", obstacles, 1486, 743);


    vector<vector<int>> blocked = {{0, 1}, {1, 0}};
    vector<int> source = {0, 0};
    vector<int> target = {0, 2};
    cout << myLeetCode.isEscapePossible(blocked, source, target);

    cout << endl;
    return 0;
}