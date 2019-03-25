#include <iostream>
#include <vector>
#include "MyLeetCode.h"

using namespace std;

int main() {

    MyLeetCode myLeetCode;
    vector<vector<int>> res = myLeetCode.largeGroupPositions("abbxxxxzzy");
    for (auto &re : res) {
        cout << re[0] << re[1] << endl;
    }
    cout << endl;
    return 0;
}