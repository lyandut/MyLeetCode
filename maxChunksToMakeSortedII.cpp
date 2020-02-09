//
// Created by 李研 on 2020/2/9.
//

#include "MyLeetCode.h"

/*
 * 768. Max Chunks To Make Sorted II
 * https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
 *【专题】Array
 */

/*
 * 方法一: 双指针
 */
//int MyLeetCode::maxChunksToSortedII(vector<int> &arr) {
//    int left = 0, right = 0, right_tmp = 0;
//    int res = 0;
//    auto brr = arr;
//    sort(brr.begin(), brr.end());
//    while (left < arr.size()) {
//        right = find(brr.begin(), brr.end(), arr[left]) - brr.begin();
//        while (left < right) {
//            left++;
//            if (arr[left] == brr[right]) {
//                right++;
//            } else {
//                right_tmp = find(brr.begin(), brr.end(), arr[left]) - brr.begin();
//                right = max(right, right_tmp);
//            }
//        }
//        res++;
//        left++;
//    }
//    return res;
//}

/*
 * 方法二: 排序求和
 */
int MyLeetCode::maxChunksToSortedII(vector<int> &arr) {
    int res = 0;
    long sumA = 0, sumB = 0;
    auto brr = arr;
    sort(brr.begin(), brr.end());
    for (int i = 0; i < arr.size(); i++) {
        sumA += arr[i];
        sumB += brr[i];
        if (sumA == sumB)
            res++;
    }
    return res;
}