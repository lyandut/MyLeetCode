//
// Created by 李研 on 2020/1/11.
//

/*
 * 621. Task Scheduler
 * https://leetcode.com/problems/task-scheduler/
 *【专题】Array；Greedy；Queue
 */

#include "MyLeetCode.h"

int MyLeetCode::leastInterval(vector<char> &tasks, int n) {
    vector<int> taskCout(26, 0);
    int maxLength = 0;
    for(auto i : tasks){
        taskCout[i - 'A']++;
        maxLength = max(taskCout[i - 'A'], maxLength);
    }
    int taskKind = count(taskCout.begin(), taskCout.end(), maxLength);
    return max((n+1) * (maxLength-1) + taskKind, (int)tasks.size());
}