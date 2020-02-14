//
// Created by 李研 on 2020/2/14.
//

/*
 * 315. Count of Smaller Numbers After Self
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 * [归并排序]
 */

#include "MyLeetCode.h"

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