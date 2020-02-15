//
// Created by 李研 on 2020/2/15.
//

#include "MyLeetCode.h"

/*
 * 630. Course Schedule III
 * https://leetcode.com/problems/course-schedule-iii/
 * [优先队列]
 */

int MyLeetCode::scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(), [](const auto &lhs, const auto &rhs) {
        return lhs[1] < rhs[1];
    });
    int d = 0;
    priority_queue<int> t;
    for (auto &course : courses) {
        if (course[0] > course[1]) continue; // 不合格课程
        if (d + course[0] <= course[1]) { // 可以选课
            d += course[0];
            t.push(course[0]);
        } else if (course[0] < t.top()) { // 调课
            d = d - t.top() + course[0];
            t.pop();
            t.push(course[0]);
        } else { // course[0] >= t.top()
            continue; // 不选课
        }
    }
    return t.size();
}