//
// Created by 李研 on 2020/2/14.
//

#include "MyLeetCode.h"

/*
 * 207. Course Schedule
 * https://leetcode.com/problems/course-schedule/
 * [拓扑排序]
 */

enum State {
    NoVisited, Visited, Visiting
};

static bool dfs(int course_id, const vector<vector<int>> &graph, vector<State> &states) {
    if (states[course_id] == State::Visiting) return false; // 有环，不可行
    if (states[course_id] == State::Visited) return true;
    states[course_id] = State::Visiting;
    for (auto next_course : graph[course_id]) {
        if (!dfs(next_course, graph, states))
            return false;
    }
    states[course_id] = State::Visited;
    return true;
}

bool MyLeetCode::canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // build graph
    vector<vector<int>> graph(numCourses);
    for (auto &each : prerequisites) {
        graph[each.back()].push_back(each.front());
    }
    // traverse
    vector<State> states(numCourses, State::NoVisited);
    for (int i = 0; i < numCourses; ++i) {
        if (states[i] == State::NoVisited && !dfs(i, graph, states))
            return false;
    }
    return true;
}