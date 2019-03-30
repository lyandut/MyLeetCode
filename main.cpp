#include <iostream>
#include <vector>
#include "MyLeetCode.h"

using namespace std;

int main() {

    MyLeetCode myLeetCode;
    myLeetCode.book(1, 3);
    cout << get<2>(myLeetCode.startEndInterval[0]);
    cout << endl;
    return 0;
}