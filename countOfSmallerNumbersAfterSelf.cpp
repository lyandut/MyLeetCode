//
// Created by 李研 on 2020/2/14.
//

/*
 * 315. Count of Smaller Numbers After Self
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 * [归并排序 | 树状数组]
 */

#include "MyLeetCode.h"

/*
 * 解法一：归并排序
 */
using ValIndexPair = pair<int, int>;

static void
merge(vector<ValIndexPair> &items, int lo_start, int lo_end, int hi_start, int hi_end, vector<int> &counts) {
    int lo_ptr = lo_start, hi_ptr = hi_start;
    vector<ValIndexPair> sorted(hi_end - lo_start + 1);
    int sorted_index = 0;
    int right_count = 0;
    while (lo_ptr <= lo_end && hi_ptr <= hi_end) {
        if (items[hi_ptr].first < items[lo_ptr].first) {
            ++right_count;
            sorted[sorted_index++] = items[hi_ptr++];
        } else {
            counts[items[lo_ptr].second] += right_count;
            sorted[sorted_index++] = items[lo_ptr++];
        }
    }

    while (lo_ptr <= lo_end) {
        counts[items[lo_ptr].second] += right_count;
        sorted[sorted_index++] = items[lo_ptr++];
    }

    while (hi_ptr <= hi_end) {
        sorted[sorted_index++] = items[hi_ptr++];
    }

    copy(sorted.begin(), sorted.end(), items.begin() + lo_start);
}

static void mergeSort(vector<ValIndexPair> &items, int start, int end, vector<int> &counts) {
    if (start >= end) return;
    int mid = start + ((end - start) >> 1);
    mergeSort(items, start, mid, counts);
    mergeSort(items, mid + 1, end, counts);
    merge(items, start, mid, mid + 1, end, counts);
}

vector<int> MyLeetCode::countSmaller(vector<int> &nums) {
    vector<ValIndexPair> items;
    items.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        items.emplace_back(nums[i], i);
    }
    vector<int> counts(nums.size());
    mergeSort(items, 0, nums.size() - 1, counts);
    return counts;
}

/*
 * 解法二：树状数组
 */
//vector<int> MyLeetCode::countSmaller(vector<int> &nums) {
//    // 使用 set 排序并去重
//    set<int> sorted(nums.begin(), nums.end());
//    // 使用 unordered_map 映射元素的 rank
//    unordered_map<int, int> ranks;
//    int rank = 0;
//    for (int num : sorted) { ranks[num] = ++rank; }
//
//    vector<int> ans;
//    FenwickTree tree(ranks.size());
//    // 倒序遍历
//    for (auto r_iter = nums.rbegin(); r_iter != nums.rend(); ++r_iter) {
//        int rank = ranks[(*r_iter)];
//        // 求小于当前 rank 的 rank 出现频率的和，往 ans 数组头部插入
//        ans.insert(ans.begin(), tree.query(rank - 1));
//        // 当前 rank 频率 +1
//        tree.update(rank, 1);
//    }
//    return ans;
//}
