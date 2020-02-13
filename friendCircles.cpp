//
// Created by 李研 on 2020/2/13.
//

#include "MyLeetCode.h"

/*
 * 547. Friend Circles
 * https://leetcode.com/problems/friend-circles/
 * [并查集]
 */

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    bool isRoot(int x) {
        return parent[x] == x;
    }

    int findNaive(int x) { // 非路径压缩
        return isRoot(x) ? x : findNaive(parent[x]);
    }

    int findByPathCompress(int x) { // 路径压缩
        return isRoot(x) ? x : parent[x] = findByPathCompress(parent[x]);
    }

    void unionNaive(int x, int y) {
        int parentX = findNaive(x);
        int parentY = findNaive(y);
        parent[parentX] = parentY;
    }

    void unionByRank(int x, int y) {
        int parentX = findByPathCompress(x);
        int parentY = findByPathCompress(y);

        // Attach smaller rank tree under root of high rank tree
        if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
            ++rank[parentX];
        } else {
            parent[parentY] = parentX;
            ++rank[parentY];
        }
    }
};

int MyLeetCode::findCircleNum(vector<vector<int>> &M) {
    if (M.empty()) return 0;
    UnionFind uf(M.size());
    for (int i = 0; i < M.size(); ++i)
        for (int j = i + 1; j < M.size(); ++j)
            if (M[i][j]) {
                uf.unionByRank(i, j);
                // uf.unionNaive(i, j);
            }


    int res = 0;
    for (int i = 0; i < M.size(); ++i)
        if (uf.isRoot(i))
            ++res;

    return res;
}