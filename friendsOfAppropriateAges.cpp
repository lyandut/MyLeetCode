//
// Created by liyan on 2019-05-30.
//

/*
 * 825. Friends Of Appropriate Ages
 * https://leetcode.com/problems/friends-of-appropriate-ages/
 */

/*
 * age[B] <= 0.5 * age[A] + 7         1. 大于等于15岁同岁交友；
 * age[B] > age[A]              ====> 2. 大于等于16岁可以和比自己小且满足条件1的交友。
 * age[B] > 100 && age[A] < 100
 */
#include "MyLeetCode.h"

int MyLeetCode::numFriendRequests(vector<int> &ages) {
    vector<int> ageMap(121, 0);
    for(int age : ages){ ageMap[age]++; }
    int count = ageMap[15] * (ageMap[15]-1);
    for(int i=16; i<121; ++i){
        count += ageMap[i] * (ageMap[i]-1); // 同岁交友
        for(int j=i-1; j>(0.5*i+7); --j){
            count += ageMap[i] * ageMap[j]; // 和比自己小且满足条件1的交友
        }
    }
    return count;
}