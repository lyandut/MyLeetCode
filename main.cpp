#include "MyLeetCode.h"

int main() {

//    vector<int> A = {2, 4, 7, 8, 9, 10, 14, 15, 18, 23, 32, 50};
//    cout << MyLeetCode::lenLongestFibSubseq(A);
//
//    vector<int> A = {2, 1, 2, 4, 2, 2}, B = {5, 2, 6, 2, 3, 2};
//    cout << MyLeetCode::minDominoRotations(A, B);
//
//    vector<int> A = {14, 4, 5, 14, 13, 14, 10, 17, 2, 12, 2, 14, 7, 13, 14, 13, 4, 16, 4, 10};
//    MyLeetCode::minIncrementForUnique(A);
//
//    vector<vector<int>> A = {{1, 1, 0},
//                             {0, 0, 1},
//                             {0, 0, 1}};
//    cout << MyLeetCode::movesToChessboard(A);
//
//    vector<vector<int>> A = {{2},
//                             {3, 4},
//                             {6, 5, 7},
//                             {4, 1, 8, 3}};
//    cout << MyLeetCode::minimumTotal(A);
//
//    vector<vector<int>> obstacles{{5,  5},
//                                  {9,  4},
//                                  {9,  7},
//                                  {6,  4},
//                                  {7,  0},
//                                  {9,  5},
//                                  {10, 7},
//                                  {1,  1},
//                                  {7,  5}};
//    MyLeetCode::robot("RRU", obstacles, 1486, 743);

//    vector<vector<int>> blocked = {{0, 1},
//                                   {1, 0}};
//    vector<int> source = {0, 0};
//    vector<int> target = {0, 2};
//    cout << MyLeetCode::isEscapePossible(blocked, source, target);

//    vector<vector<int>> leadership{{1, 2},
//                                   {1, 6},
//                                   {2, 3},
//                                   {2, 5},
//                                   {1, 4}};
//    vector<vector<int>> operations{{1, 1, 500},
//                                   {2, 2, 50},
//                                   {3, 1},
//                                   {2, 6, 15},
//                                   {3, 1}};
//    vector<int> res = MyLeetCode::bonus(6, leadership, operations);
//    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));

    vector<vector<int>> increase{{2,  8, 4},
                                 {2,  5, 0},
                                 {10, 9, 8}};
    vector<vector<int>> requirements{{2,  11, 3},
                                     {15, 10, 7},
                                     {9,  17, 12},
                                     {8,  1,  14}};
    vector<int> res = MyLeetCode::getTriggerTime(increase, requirements);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));

    cout << endl;
    return 0;
}