//
// Created by 李研 on 2020/2/14.
//

#include "MyLeetCode.h"

/*
 * 210. Course Schedule II
 * https://leetcode.com/problems/course-schedule-ii/
 * [拓扑排序]
 */

enum State {
    NoVisited, Visited, Visiting
};

static bool dfs(int course_id, const vector<vector<int>> &graph, vector<State> &states, vector<int> &res) {
    if (states[course_id] == State::Visiting) return false;
    if (states[course_id] == State::Visited) return true;
    states[course_id] = State::Visiting;
    for (auto next_course : graph[course_id]) {
        if (!dfs(next_course, graph, states, res))
            return false;
    }
    states[course_id] = State::Visited;
    res.insert(res.begin(), course_id);
    return true;
}

vector<int> MyLeetCode::findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> res;
    // build graph
    vector<vector<int>> graph(numCourses);
    for (auto &each : prerequisites) {
        graph[each.back()].push_back(each.front());
    }
    // traverse
    vector<State> states(numCourses, State::NoVisited);
    for (int i = 0; i < numCourses; ++i) {
        if (states[i] == State::NoVisited && !dfs(i, graph, states, res)) {
            return {};
        }
    }
    return res;
}