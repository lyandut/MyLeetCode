//
// Created by liyan on 2018-12-31.
//
#include "MyLeetCode.h"

/*
 * https://leetcode-cn.com/problems/pascals-triangle-ii/
 *【专题】Array
 */
vector<int> MyLeetCode::getRow(int rowIndex) {
    int numRows = rowIndex + 1;
    vector<vector<int>> PascalsTriangle;
    PascalsTriangle.reserve(numRows);

    PascalsTriangle.emplace_back(vector<int>(1, 1));
    int right, left;
    for (int i = 1; i < numRows; i++) {
        vector<int> ithRow;
        for (int j = 0; j <= i; j++) {
            right = i - 1 < j ? 0 : PascalsTriangle[i - 1][j];
            left = j - 1 < 0 ? 0 : PascalsTriangle[i - 1][j - 1];
            ithRow.push_back(right + left);
        }
        PascalsTriangle.push_back(ithRow);
    }
    return PascalsTriangle[rowIndex];
}

/*
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/
 *【专题】Array
 */
vector<bool> MyLeetCode::prefixesDivBy5(vector<int> &A) {
    vector<bool> res;
    res.reserve(A.size());
    int iAnswer = 0;
    for (int a : A) {
        iAnswer = (iAnswer * 2 + a) % 5;
        res.push_back(iAnswer == 0);
    }
    return res;
}

/*
 * https://leetcode.com/problems/add-to-array-form-of-integer/
 *【专题】Array
 */
vector<int> MyLeetCode::addToArrayForm(vector<int> &A, int K) {
    int index = A.size();
    while (index && K) {
        K = A[index - 1] + K;
        A[index - 1] = K % 10;
        K /= 10;
        index--;
    }
    while (K) {
        A.insert(A.begin(), K % 10);
        K /= 10;
    }
    return A;
}

/*
 * https://leetcode-cn.com/problems/valid-triangle-number/
 *【专题】Array
 */
int MyLeetCode::triangleNumber(vector<int> &nums) {
    int count = 0;
    sort(nums.begin(), nums.end());
    for (int i = 2; i < nums.size(); i++) {
        for (int j = 0; j < i - 1; j++) {
            for (int k = j + 1; k < i; k++) {
                if (nums[j] + nums[k] > nums[i]) {
                    count += i - k;
                    break;
                }
            }
        }
    }
    return count;
}

/*
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 *【专题】Array
 */
int MyLeetCode::numPairsDivisibleBy60(vector<int> &time) {
    int count = 0;
    int mod[60] = {0};
    for (int each : time) {
        mod[each % 60]++;
    }
    for (int i = 1; i < 30; i++) {
        count += mod[i] * mod[60 - i];
    }
    count += mod[0] * (mod[0] - 1) / 2;
    count += mod[30] * (mod[30] - 1) / 2;
    return count;
}

/*
 * https://leetcode-cn.com/problems/remove-element/
 *【专题】Array；Two Pointers
 */
int MyLeetCode::removeElement(vector<int> &nums, int val) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        while (left < nums.size() && nums[left] != val) { left++; }
        while (right >= 0 && nums[right] == val) { right--; }
        if (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
    }
    return left;
}

/*
 * https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
 *【专题】Array
 */
int MyLeetCode::findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty()) { return 0; }
    int head = -1;
    int maxSize = 0;
    for (int i = 0; i < nums.size(); i++) {
        if ((i < nums.size() - 1 && nums[i] >= nums[i + 1]) || i == nums.size() - 1) {
            maxSize = max(maxSize, i - head);
            head = i;
        }
    }
    return maxSize;
}

/*
 * https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
 *【专题】Array；Dynamic Programming
 */
vector<int> MyLeetCode::maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int length = nums.size();
    vector<int> sum(length, nums[0]);
    for (int i = 1; i < length; i++) {
        sum[i] = sum[i - 1] + nums[i];
    }
    int firstMaxIndex = length - 2 * k - 1;
    int thirdMinIndex = 2 * k;
    int secondMinIndex = k;
    int secondMaxIndex = length - k - 1;
    vector<pair<int, int>> firstDp(firstMaxIndex + 1, make_pair(0, 0));
    vector<pair<int, int>> thirdDp(length, make_pair(length - k, 0));
    int newSum;
    for (int i = 0; i <= firstMaxIndex; i++) {
        if (i < secondMinIndex) {
            newSum = sum[k - 1];
            firstDp[i].first = 0;
            firstDp[i].second = newSum;
        } else {
            newSum = sum[i] - sum[i - k];
            if (newSum > firstDp[i - 1].second) {
                firstDp[i].first = i - k + 1;
                firstDp[i].second = newSum;
            } else {
                firstDp[i] = firstDp[i - 1];
            }
        }
    }
    for (int i = length - 1; i >= thirdMinIndex; i--) {
        if (i > secondMaxIndex) {
            newSum = sum[length - 1] - sum[length - 1 - k];
            thirdDp[i].first = length - k;
            thirdDp[i].second = newSum;
        } else {
            newSum = sum[i + k - 1] - sum[i - 1];
            if (newSum >= thirdDp[i + 1].second) {
                thirdDp[i].first = i;
                thirdDp[i].second = newSum;
            } else {
                thirdDp[i] = thirdDp[i + 1];
            }
        }
    }
    int total = 0;
    vector<int> res;
    for (int i = secondMinIndex; i <= secondMaxIndex - k + 1; i++) {
        newSum = sum[i + k - 1] - sum[i - 1];
        if (newSum + firstDp[i - 1].second + thirdDp[i + k].second > total) {
            total = newSum + firstDp[i - 1].second + thirdDp[i + k].second;
            res = {firstDp[i - 1].first, i, thirdDp[i + k].first};
        }
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/container-with-most-water/
 *【专题】Array；Two Pointers
 */
int MyLeetCode::maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int result = 0;
    while (left < right) {
        int newContain = min(height[left], height[right]) * (right - left);
        if (newContain > result) {
            result = newContain;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}

/*
 * https://leetcode.com/problems/subarray-sums-divisible-by-k/
 *【专题】Array；Hash Table
 */
int MyLeetCode::subarraysDivByK(vector<int> &A, int K) {
    int res = 0;
    vector<int> subArraySum(A.size() + 1, 0);
    vector<int> hashTable(K, 0);
    hashTable[(subArraySum[0] % K + K) % K]++;
    for (int i = 0; i < A.size(); i++) {
        subArraySum[i + 1] = subArraySum[i] + A[i];
        hashTable[(subArraySum[i + 1] % K + K) % K]++;
    }
    for (auto each : hashTable) {
        res += each * (each - 1) / 2;
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/number-of-subarrays-with-bounded-maximum/
 *【专题】Array
 */
int MyLeetCode::numSubarrayBoundedMax(vector<int> &A, int L, int R) {
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > R) { continue; }
        if (A[i] >= L) { count++; }
        int curMax = A[i];
        for (int j = i + 1; j < A.size(); j++) {
            curMax = max(curMax, A[j]);
            if (curMax > R) { break; }
            if (curMax >= L) { count++; }
        }
    }
    return count;
}

/*
 * https://leetcode-cn.com/problems/partition-array-into-disjoint-intervals/
 *【专题】Array
 */
int MyLeetCode::partitionDisjoint(vector<int> &A) {
    int left = 0, right = A.size() - 1;
    int leftMax = A[left], rightMin = A[right];
    while (left != right - 1) {
        while (A[left + 1] < leftMax) { left++; }
        while (A[right - 1] >= leftMax && right - 1 > left) {
            rightMin = min(A[right - 1], rightMin);
            right--;
        }
        for (int i = left; i < right; i++) {
            leftMax = max(leftMax, A[i]);
        }
        left = right - 1;
        if (leftMax > rightMin) {
            right = A.size() - 1;
            rightMin = A[right];
        }
    }
    return right;
}

/*
 * https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
 *【专题】Array
 */
int MyLeetCode::minIncrementForUnique(vector<int> &A) {
    int res = 0;
    vector<int> vec(40001, 0);
    vector<int> dupVec;
    for (int each : A) {
        vec[each]++;
        if (vec[each] > 1) { dupVec.push_back(each); }
    }
    if (dupVec.empty()) { return 0; }
    sort(dupVec.begin(), dupVec.end());
    auto iter = dupVec.begin();
    for (int i = (*iter) + 1; iter != dupVec.end(); i++) {
        if (vec[i] == 0 && i > (*iter)) {
            res += i - (*iter);
            vec[i]++;
            iter++;
        }
    }
    return res;
}

/*
 * https://leetcode.com/problems/number-of-matching-subsequences/
 *【专题】Array
 */
int MyLeetCode::numMatchingSubseq(string S, vector<string> &words) {
    int count = 0;
    unordered_map<char, vector<int>> hashMap;
    for (int i = 0; i < S.size(); i++) {
        hashMap[S[i]].push_back(i);
    }
    for (string &word : words) {
        if (hashMap[word[0]].empty()) { continue; }
        int currIndex = hashMap[word[0]][0];
        int j;
        for (j = 1; j < word.size(); j++) {
            if (hashMap[word[j]].empty()) { break; }
            int oldIndex = currIndex;
            for (int hashIndex : hashMap[word[j]]) {
                if (hashIndex > currIndex) {
                    currIndex = hashIndex;
                    break;
                }
            }
            if (currIndex == oldIndex) { break; }
        }
        if (j == word.size()) { count++; }
    }
    return count;
}

/*
 * https://leetcode-cn.com/problems/advantage-shuffle/
 *【专题】Array
 */
vector<int> MyLeetCode::advantageCount(vector<int> &A, vector<int> &B) {
    int length = A.size();
    vector<int> res(length);
    multimap<int, int> bIndexMap;
    for (int i = 0; i < length; i++) {
        bIndexMap.insert(make_pair(B[i], i));
    }
    sort(A.begin(), A.end());
    auto r_iter = bIndexMap.rbegin();
    int left = 0, right = length - 1;
    while (left <= right) {
        if ((*r_iter).first >= A[right]) {
            res[(*r_iter).second] = A[left++];
        } else {
            res[(*r_iter).second] = A[right--];
        }
        r_iter++;
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/subsets/
 *【专题】Array
 */
vector<vector<int>> MyLeetCode::subsets(vector<int> &nums) {
    vector<vector<int>> res;
    res.emplace_back(vector<int>());
    for (int num : nums) {
        auto subSet = res;
        for (auto each : subSet) {
            each.push_back(num);
            res.push_back(each);
        }
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/subsets-ii/
 *【专题】Array
 */
vector<vector<int>> MyLeetCode::subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    res.emplace_back(vector<int>());
    sort(nums.begin(), nums.end());
    int dupCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0 && nums[i] == nums[i - 1]) {
            dupCount++;
            auto subSet = res;
            for (auto each : subSet) {
                if (count(each.begin(), each.end(), nums[i]) == dupCount) {
                    each.push_back(nums[i]);
                    res.push_back(each);
                }
            }
        } else {
            dupCount = 0;
            auto subSet = res;
            for (auto each : subSet) {
                each.push_back(nums[i]);
                res.push_back(each);
            }
        }

    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/
 *【专题】Array；Hash Table
 */
int MyLeetCode::subarraySum(vector<int> &nums, int k) {
    map<int, int> sumMap;
    int sum = 0, res = 0;
    sumMap[sum] = 1;
    for (int num : nums) {
        sum += num;
        if (sumMap.find(sum - k) != sumMap.end()) {
            res += sumMap[sum - k];
        }
        sumMap[sum]++;
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/
 *【专题】Array；Union Find
 */
int MyLeetCode::longestConsecutive(vector<int> &nums) {
    map<int, int> hashMap;
    int left, right, curr, max = 0;
    for (int num : nums) {
        if (hashMap[num]) { continue; }
        left = hashMap[num - 1];
        right = hashMap[num + 1];
        hashMap[num] = curr = left + right + 1;
        hashMap[num - left] = curr;
        hashMap[num + right] = curr;
        max = curr > max ? curr : max;
    }
    return max;
}

/*
 * https://leetcode-cn.com/problems/find-peak-element/
 *【专题】Array；Binary Search
 */
int MyLeetCode::findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] < nums[mid + 1])
            left = mid + 1;
        else if (mid > 0 && nums[mid] < nums[mid - 1])
            right = mid - 1;
        else
            return mid;
    }
    return left;
}

/*
 * https://leetcode-cn.com/problems/plus-one/
 *【专题】Array
 */
vector<int> MyLeetCode::plusOne(vector<int> &digits) {
    int c = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
        int sum = digits[i] + c;
        digits[i] = sum % 10;
        c = sum / 10;
    }
    if (c) { digits.insert(digits.begin(), 1); }
    return digits;
}

/*
 * https://leetcode-cn.com/problems/find-pivot-index/
 *【专题】Array
 */
int MyLeetCode::pivotIndex(vector<int> &nums) {
    vector<int> sums;
    sums.push_back(0);
    for (int i = 0; i < nums.size(); i++) {
        sums.push_back(sums[i] + nums[i]);
    }
    for (int j = 0; j < nums.size(); j++) {
        if (sums[j] == sums[sums.size() - 1] - sums[j + 1])
            return j;
    }
    return -1;
}