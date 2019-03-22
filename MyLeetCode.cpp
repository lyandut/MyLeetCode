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
/*
 * 方法一: 双指针
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




