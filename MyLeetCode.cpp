//
// Created by liyan on 2018-12-31.
//
#include "MyLeetCode.h"

/*
 * https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 */
/*
 * 方法一: 二分查找
 */
int MyLeetCode::singleNonDuplicate(vector<int> &nums) {
    int left = 0;
    int right = nums.size()-1;
    while (left < right){
        int mid = (left+right)/2;
        int lremain;
        int rremain;
        if(nums[mid] == nums[mid-1]){
            lremain = (mid-1) - left;
            rremain = right - mid;
            if(lremain%2 == 0)
                left = mid + 1;
            else
                right = mid - 2;
        }
        else if(nums[mid] == nums[mid+1]){
            lremain = mid - left;
            rremain = right - (mid+1);
            if(rremain%2 == 0)
                right = mid - 1;
            else
                left = mid + 2;
        }
        else
            left = mid;
    }
    return nums[left];
}

/*
 * 方法二: 异或
 */
//int MyLeetCode::singleNonDuplicate(vector<int> &nums) {
//    int res = 0;
//    for(int i=0; i<nums.size(); i++){
//        res^=nums[i];
//    }
//    return res;
//}

/*
 * https://leetcode-cn.com/problems/is-subsequence/
 */
bool MyLeetCode::isSubsequence(string s, string t) {
    if(s.length()==0 && t.length()==0)
        return true;
    for(int i=0, j=0; j < t.length(); j++){
        if(s[i] == t[j])
            i++;
        if(i==s.length())
            return true;
    }
    return false;
}


/*
 * https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/
 * [tag] 数学
 */
bool MyLeetCode::isOneBitCharacter(vector<int> &bits) {
    auto iter = bits.rbegin()+1;
    int count = 0;
    while(iter != bits.rend()) {
        if ((*iter) == 1)
            count++;
        else
            break;
        ++iter;
    }
    bool flag = count % 2 == 0;
    return flag;
}

/*
 * https://leetcode-cn.com/problems/find-the-duplicate-number/
 * [tag] O(1)空间交换
 */
int MyLeetCode::findDuplicate(vector<int> &nums) {
    int temp;
    while (true){
        if(nums[nums[0]]!=nums[0]){
            temp = nums[0];
            nums[0] = nums[temp];
            nums[temp]= temp;
        }
        else
            break;
    }
    return nums[0];
}

/*
 * https://leetcode-cn.com/problems/flip-string-to-monotone-increasing/
 * [tag] 数学
 */
int MyLeetCode::minFlipsMonoIncr(string S) {
    int zeroCount = count(S.begin(), S.end(), '0');
    int oneCount = count(S.begin(), S.end(), '1');
    int minCount = S.size();
    for(int i=0; i<S.size()-1; i++){
        if(S[i]=='0' && S[i+1]=='1') {
//            minCount = min(minCount, count(S.begin(), S.begin()+i, '1') + count(S.begin()+i+2, S.end(), '0'));
            int totalCount = count(S.begin(), S.begin()+i, '1') + count(S.begin()+i+2, S.end(), '0');
            minCount = minCount < totalCount ? minCount : totalCount;
        }
    }
    return min(min(zeroCount, oneCount), minCount);
}

/*
 * https://leetcode-cn.com/problems/image-smoother/
 * [tag] 暴力
 */
vector<vector<int>> MyLeetCode::imageSmoother(vector<vector<int>> &M) {
    int row = M.size();
    int col = M[0].size();
    vector<vector<int>> avgRes(row, vector<int>(col, 0));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            int sum = M[i][j];
            int count = 1;
            bool up = i-1>=0, down = i+1<row, left = j-1>=0, right = j+1<col;
            if(up && left) {
                sum += M[i - 1][j - 1];
                count++;
            }
            if(up) {
                sum += M[i - 1][j];
                count++;
            }
            if(up && right) {
                sum += M[i - 1][j + 1];
                count++;
            }
            if(left) {
                sum += M[i][j - 1];
                count++;
            }
            if(right) {
                sum += M[i][j + 1];
                count++;
            }
            if(down && left) {
                sum += M[i + 1][j - 1];
                count++;
            }
            if(down) {
                sum += M[i + 1][j];
                count++;
            }
            if(down && right) {
                sum += M[i + 1][j + 1];
                count++;
            }
            avgRes[i][j] = sum / count;
        }
    }
    return avgRes;
}

/*
 * https://leetcode-cn.com/problems/missing-number/
 * 异或
 */
int MyLeetCode::missingNumber(vector<int> &nums) {
    int n = nums.size();
    for(int i=0; i<nums.size(); i++){
        n ^= nums[i];
        n ^= i;
    }
    return n;
}

/*
 * https://leetcode-cn.com/problems/positions-of-large-groups/
 * 双指针
 */
vector<vector<int>> MyLeetCode::largeGroupPositions(string S) {
    vector<vector<int>> res;
    for(int i=0, j=i+1; i<S.size() && j<S.size();){
        if(S[i] == S[j]){
            j++;
        }
        if(S[i] != S[j]){
            if(j-i>2){
                vector<int> group = {i, j-1};
                res.push_back(group);
            }
            i = j;
            j += 1;
        }
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/rotate-image/
 * 数学
 */
void MyLeetCode::rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for(int i=0; i<n/2; i++){
        for(int j=i; j<n-1-i; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];           // 左上 <- 左下
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];   // 左下 <- 右下
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];   // 右下 <- 右上
            matrix[j][n-1-i] = temp;                   // 右上 <- 左上
        }
    }
}

/*
 * https://leetcode-cn.com/problems/combination-sum/comments/
 * 递归、回溯、动态规划、BFS
 */
vector<vector<int>> MyLeetCode::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> Res;
    vector<int> Sum;
    sort(candidates.begin(), candidates.end());
    recursive(candidates, target, Res, Sum, 0);
    return Res;
}

void MyLeetCode::recursive(vector<int> &candidates, int target, vector<vector<int>> &Res, vector<int> &Sum, int index){
    if (target == 0){
        Res.push_back(Sum);
        return;
    }
    if(target < 0) return;
    for(int i=index; i<candidates.size(); i++){
        Sum.push_back(candidates[i]);
        recursive(candidates, target-candidates[i], Res, Sum, i);
        Sum.pop_back();
    }
}


/*
 * https://leetcode-cn.com/problems/my-calendar-i/
 * 优化：二分查找插入、BST
 */
bool MyLeetCode::book(int start, int end) {
    if(startEndInterval.empty()){
        startEndInterval.emplace_back(start, end, end-start);
        return true;
    }
    if(start >= get<1>(*startEndInterval.rbegin())){
        startEndInterval.emplace_back(start, end, end-start);
        return true;
    }
    if(end <= get<0>(*startEndInterval.begin())){
        startEndInterval.insert(startEndInterval.begin(), make_tuple(start, end, end-start));
        return true;
    }
    else{
        for(int i=0; i<startEndInterval.size(); i++){
            if(start >= get<1>(startEndInterval[i]) && end <= get<0>(startEndInterval[i+1])){
                startEndInterval.insert(startEndInterval.begin()+i+1, make_tuple(start, end, end-start));
                return true;
            }
            if(start >= get<0>(startEndInterval[i]) && start < get<1>(startEndInterval[i]))
                return false;
            if(end > get<0>(startEndInterval[i]) && end < get<1>(startEndInterval[i]))
                return false;
        }
    }
    return false;
}

/*
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */
int MyLeetCode::maxProfit(vector<int> &prices) {
    int maxPro = 0;
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++) {
            if (prices[j] > prices[i] && maxPro < prices[j] - prices[i])
                maxPro = prices[j] - prices[i];
        }
    }
    return maxPro;
}

/*
 * https://leetcode-cn.com/problems/unique-paths/
 * 递归、动态规划
 */
int MyLeetCode::uniquePaths(int m, int n) {
    vector<vector<int>> Paths(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++) {
            if (i == 1 || j == 1)
                Paths[i][j] = 1;
            else {
                Paths[i][j] = Paths[i - 1][j] + Paths[i][j - 1];
            }
        }
    }
    return Paths[m][n];
}

/*
 * https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 *【专题】Array；Dynamic Programming
 */
int MyLeetCode::minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    return _minCostClimbingStairs(cost, cost.size());
}

int MyLeetCode::_minCostClimbingStairs(vector<int> &cost, int n) {
//    if(n==0 || n==1) {
//        return cost[n];
//    }
//    return min(_minCostClimbingStairs(cost, n-1), _minCostClimbingStairs(cost, n-2)) + cost[n];
    vector<int> Costs(n, 0);
    for(int i=0; i<n; i++){
        if(i==0 || i==1)
            Costs[i] = cost[i];
        else
            Costs[i] = min(Costs[i-1], Costs[i-2]) + cost[i];
    }
    return Costs[n-1];
}

/*
 * https://leetcode-cn.com/problems/minimum-path-sum/
 *【专题】Array；Dynamic Programming
 */
int MyLeetCode::minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    return _minPathSum(grid, m, n);
}

int MyLeetCode::_minPathSum(vector<vector<int>> &grid, int m, int n){
    vector<vector<int>> Paths(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) {
            if (i == 0 && j == 0)
                Paths[i][j] = grid[i][j];
            else if(i == 0 && j > 0)
                Paths[i][j] = Paths[i][j-1] + grid[i][j];
            else if(i > 0 && j == 0)
                Paths[i][j] = Paths[i-1][j] + grid[i][j];
            else
                Paths[i][j] = min(Paths[i - 1][j], Paths[i][j - 1]) + grid[i][j];
        }
    }
    return Paths[m-1][n-1];
}


/*
 * https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/
 *【专题】Array；Dynamic Programming
 */
/*
 * 解法1. 暴力搜索，26/33个通过测试用例
 */
//int MyLeetCode::lenLongestFibSubseq(vector<int> &A) {
//    int result = 0;
//    for(int i=0; i<A.size()-2; i++){
//        for(int j=i+1; j<A.size()-1; j++){
//            int length = 2;
//            auto iIter = A.begin() + i;
//            auto jIter = A.begin() + j;
//            auto fibIter = find(jIter+1, A.end(), *iIter + *jIter);
//            while(fibIter != A.end()){
//                length++;
//                iIter = jIter;
//                jIter = fibIter;
//                fibIter = find(jIter+1, A.end(), *iIter + *jIter);
//            }
//            result = result > length ? result : length;
//        }
//    }
//    return result > 2 ? result : 0;
//}
/*
 * 解法2. 动态规划
 * A[i] = A[j] + A[k]
 * dp[i][j] = dp[j][k] + 1
 */
int MyLeetCode::lenLongestFibSubseq(vector<int> &A) {
    map<int, int> valueIndex;
    for(int i=0; i<A.size(); i++) {
        valueIndex[A[i]] = i;
    }
    int result = 0;
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 2));
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<i; j++){
            int Ak = A[i] - A[j];
            if(Ak < A[j] && valueIndex.count(Ak)){
                int k = valueIndex[Ak];
                dp[i][j] = dp[j][k] + 1;
                result = result > dp[i][j] ? result : dp[i][j];
            }
        }
    }
    return result > 2 ? result : 0;
}

/*
 * https://leetcode-cn.com/problems/spiral-matrix-ii/
 *【专题】Array
 */
vector<vector<int>> MyLeetCode::generateMatrix(int n) {
    vector<vector<int>> Matrix(n, vector<int>(n));
    int iter = 0;
    int val = 1;
    while(val <= n*n){
        for(int i=iter; i<n-iter; i++)
            Matrix[iter][i] = val++;
        for(int i=iter+1; i<n-iter; i++)
            Matrix[i][n-1-iter] = val++;
        for(int i=n-2-iter; i>=iter; i--)
            Matrix[n-1-iter][i] = val++;
        for(int i=n-2-iter; i>iter; i--)
            Matrix[i][iter] = val++;

        iter++;
    }
    return Matrix;
}


/*
 * https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
 *【专题】Array；Greedy
 */
int MyLeetCode::minDominoRotations(vector<int> &A, vector<int> &B) {
    int length = A.size();
    int sameA = A[0], sameB = B[0];
    int i, resA = 0, resB = 0;
    for(i=0; i<length; i++){
        if(!(A[i] == sameA || B[i] == sameA))   break;
        if(A[i] != sameA)   resA++;
        if(B[i] != sameA)   resB++;
        if(i == length-1)   return resA > resB ? resB : resA;
    }
    resA = 0, resB = 0;
    for(i=0; i<length; i++){
        if(A[i] != sameB && B[i] != sameB)  break;
        if(A[i] != sameB)   resA++;
        if(B[i] != sameB)   resB++;
        if(i == length-1)   return resA > resB ? resB : resA;
    }

    return -1;
}


/*
 * https://leetcode.com/problems/best-sightseeing-pair/
 *【专题】Array
 */
int MyLeetCode::maxScoreSightseeingPair(vector<int> &A) {
    int valAddIndex = 0, valSubIndex = 0, maxScore = 0;
    for(int i=0; i<A.size()-1; i++){
        valAddIndex = max(valAddIndex, A[i] + i);
        valSubIndex = A[i+1] - (i+1);
        maxScore = max(maxScore, valAddIndex + valSubIndex);
    }
    return maxScore;
}

/*
 * https://leetcode-cn.com/problems/max-chunks-to-make-sorted/
 */
int MyLeetCode::maxChunksToSorted(vector<int> &arr) {
    int left = 0, right = 0;
    int res = 0;
    while(left < arr.size()){
        right = arr[left];
        while(left < right){
            left++;
            right = max(right, arr[left]);
        }
        res++;
        left++;
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/max-chunks-to-make-sorted-ii/
 *【专题】Array
 */
/* 方法一: 双指针 */
//int MyLeetCode::maxChunksToSortedII(vector<int> &arr) {
//    int left = 0, right = 0, right_tmp = 0;
//    int res = 0;
//    auto brr = arr;
//    sort(brr.begin(), brr.end());
//    while(left < arr.size()) {
//        right = find(brr.begin(), brr.end(), arr[left]) - brr.begin();
//        while(left < right){
//            left++;
//            if(arr[left] == brr[right]) {
//                right++;
//            }
//            else {
//                right_tmp = find(brr.begin(), brr.end(), arr[left]) - brr.begin();
//                right = max(right, right_tmp);
//            }
//        }
//        res++;
//        left++;
//    }
//    return res;
//}

/* 方法二: 排序求和 */
int MyLeetCode::maxChunksToSortedII(vector<int> &arr) {
    int res = 0;
    long sumA = 0, sumB = 0;
    auto brr = arr;
    sort(brr.begin(), brr.end());
    for(int i=0; i < arr.size(); i++){
        sumA += arr[i];
        sumB += brr[i];
        if(sumA == sumB)
            res++;
    }
    return res;
}

/*
 * https://leetcode-cn.com/problems/pascals-triangle/
 *【专题】Array
 */
vector<vector<int>> MyLeetCode::generate(int numRows) {
    vector<vector<int>> PascalsTriangle;
    PascalsTriangle.reserve(numRows);
    if (numRows <= 0)
        return PascalsTriangle;

    PascalsTriangle.emplace_back(vector<int>(1, 1));
    int right, left;
    for(int i=1; i<numRows; i++) {
        vector<int> ithRow;
        for(int j=0; j<=i; j++){
            right = i-1 < j ? 0 : PascalsTriangle[i-1][j];
            left = j-1 < 0 ? 0 : PascalsTriangle[i-1][j-1];
            ithRow.push_back(right + left);
        }
        PascalsTriangle.push_back(ithRow);
    }
    return PascalsTriangle;
}

/*
 * https://leetcode-cn.com/problems/task-scheduler/
 *【专题】Array；Greedy；Queue
 */
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

/*
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/
 *【专题】Array
 */
vector<bool> MyLeetCode::prefixesDivBy5(vector<int> &A) {
    vector<bool> res;
    res.reserve(A.size());
    int iAnswer = 0;
    for(int a : A){
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
    while(index && K){
        K = A[index - 1] + K;
        A[index - 1] = K % 10;
        K /= 10;
        index--;
    }
    while(K){
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
    for(int i=2; i<nums.size(); i++){
        for(int j=0; j<i-1; j++){
            for(int k=j+1; k<i; k++){
                if(nums[j] + nums[k] > nums[i]){
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
    for(int each : time) {
        mod[each % 60]++;
    }
    for(int i=1; i<30; i++) {
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
    while (left <= right){
        while(left < nums.size() && nums[left] != val) { left++; }
        while(right >= 0 && nums[right] == val) { right--; }
        if(left < right) {
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
    if(nums.empty()) { return 0; }
    int head = -1;
    int maxSize = 0;
    for(int i=0; i<nums.size(); i++){
        if((i<nums.size()-1 && nums[i] >= nums[i+1]) || i==nums.size()-1) {
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
    for(int i=1; i<length; i++){
        sum[i] = sum[i-1] + nums[i];
    }
    int firstMaxIndex = length - 2 * k - 1;
    int thirdMinIndex = 2 * k;
    int secondMinIndex = k;
    int secondMaxIndex = length - k - 1;
    vector<pair<int, int>> firstDp(firstMaxIndex + 1, make_pair(0, 0));
    vector<pair<int, int>> thirdDp(length, make_pair(length-k, 0));
    int newSum;
    for(int i=0; i<=firstMaxIndex; i++){
        if(i < secondMinIndex){
            newSum = sum[k-1];
            firstDp[i].first = 0;
            firstDp[i].second = newSum;
        }
        else{
            newSum = sum[i] - sum[i-k];
            if(newSum > firstDp[i-1].second){
                firstDp[i].first = i-k+1;
                firstDp[i].second = newSum;
            }
            else{
                firstDp[i] = firstDp[i-1];
            }
        }
    }
    for(int i=length-1; i>=thirdMinIndex; i--){
        if(i > secondMaxIndex) {
            newSum = sum[length-1] - sum[length-1-k];
            thirdDp[i].first = length-k;
            thirdDp[i].second = newSum;
        }
        else{
            newSum = sum[i+k-1] - sum[i-1];
            if(newSum >= thirdDp[i+1].second){
                thirdDp[i].first = i;
                thirdDp[i].second = newSum;
            }
            else{
                thirdDp[i] = thirdDp[i+1];
            }
        }
    }
    int total = 0;
    vector<int> res;
    for(int i=secondMinIndex; i<=secondMaxIndex-k+1; i++) {
        newSum = sum[i+k-1] - sum[i-1];
        if(newSum + firstDp[i-1].second + thirdDp[i+k].second > total){
            total = newSum + firstDp[i-1].second + thirdDp[i+k].second;
            res = {firstDp[i-1].first, i, thirdDp[i+k].first};
        }
    }
    return res;
}
