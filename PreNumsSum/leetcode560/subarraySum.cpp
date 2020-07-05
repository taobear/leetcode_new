#include "subarraySum.h"

#include <map>

int Solution::subarraySum(std::vector<int> &nums, int k)
{
    std::map<int, int> sumsMap;
    sumsMap[0] ++;

    int currSum = 0, result = 0;
    for (auto e : nums) {
        currSum += e;
        if (sumsMap.find(currSum - k) != sumsMap.end()) {
            result += sumsMap[currSum - k];
        }

        sumsMap[currSum]++;
    }

    return result;
}