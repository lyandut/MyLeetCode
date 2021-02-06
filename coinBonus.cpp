//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * LCP 5. 发 LeetCoin
 * https://leetcode-cn.com/problems/coin-bonus/
 */

constexpr int mod = 1e9 + 7;

/* Definition for Segment Tree. */
class SegmentTree {
public:
    SegmentTree(int n) : _tree(4 * n), _lazy(4 * n) {}

    // 惰性更新
    void push_down(int pos, int left, int right) {
        if (_lazy[pos] == 0) return;
        _tree[pos] += _lazy[pos] * (right - left + 1);
        if (left < right) { // 向下传递
            _lazy[2 * pos + 1] += _lazy[pos];
            _lazy[2 * pos + 2] += _lazy[pos];
        }
        _lazy[pos] = 0; // 清理当前节点lazy
    }

    // 自上而下的更新
    void update(int pos, int value, int left, int right, int op_left, int op_right) {
        push_down(pos, left, right); // 先惰性更新才能得到正确的值
        if (right < op_left || left > op_right) return;
        if (op_left <= left && right <= op_right) {
            _lazy[pos] = value;
            push_down(pos, left, right);
            return;
        }
        int left_pos = 2 * pos + 1;
        int right_pos = 2 * pos + 2;
        int mid = left + (right - left) / 2;
        update(left_pos, value, left, mid, op_left, op_right);
        update(right_pos, value, mid + 1, right, op_left, op_right);
        _tree[pos] = _tree[left_pos] + _tree[right_pos];
    }

    long query(int pos, int left, int right, int op_left, int op_right) {
        push_down(pos, left, right); // 先惰性更新才能得到正确的值
        if (right < op_left || left > op_right) return 0;
        if (op_left <= left && right <= op_right) return _tree[pos];
        int left_pos = 2 * pos + 1;
        int right_pos = 2 * pos + 2;
        int mid = left + (right - left) / 2;
        return query(left_pos, left, mid, op_left, op_right) +
               query(right_pos, mid + 1, right, op_left, op_right);
    }

private:
    vector<long> _tree;
    vector<int> _lazy; // 惰性查询优化
};

static void dfs(int leader, int &tree_id, unordered_map<int, int> &lmap, unordered_map<int, int> &rmap,
                unordered_map<int, vector<int>> &leadershipmap) {
    ++tree_id;
    lmap[leader] = tree_id;
    for (int follower : leadershipmap[leader]) {
        dfs(follower, tree_id, lmap, rmap, leadershipmap);
    }
    rmap[leader] = tree_id;
}

vector<int> MyLeetCode::bonus(int n, vector<vector<int>> &leadership, vector<vector<int>> &operations) {
    vector<int> res;

    // 建立领导关系
    unordered_map<int, vector<int>> leadershipmap;
    for (auto &each_pair : leadership) {
        leadershipmap[each_pair[0]].push_back(each_pair[1]);
    }
    // 员工id转换为线段树id
    int tree_id = -1;
    unordered_map<int, int> lmap, rmap; // [lmap[i], rmap[i]]表示员工i及其下属的tree_id范围
    dfs(1, tree_id, lmap, rmap, leadershipmap);

    // 执行 operations
    SegmentTree seg_tree(n);
    for (auto &op : operations) {
        if (op[0] == 1) {
            seg_tree.update(0, op[2], 0, n - 1, lmap[op[1]], lmap[op[1]]);
        } else if (op[0] == 2) {
            seg_tree.update(0, op[2], 0, n - 1, lmap[op[1]], rmap[op[1]]);
        } else if (op[0] == 3) {
            res.push_back(seg_tree.query(0, 0, n - 1, lmap[op[1]], rmap[op[1]]) % mod);
        }
    }

    return res;
}