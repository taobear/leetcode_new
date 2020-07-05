#include "checkSubarraySum.h"

#include <map>
using namespace std;

bool Solution::checkSubarraySum(vector<int> &nums, int k)
{
    map<int, int> numsMap;
    numsMap[0]++;

    int kplus = k >= 0 ? k : -k;
    int currSum = 0;
    for (auto e : nums) {
        currSum += e;

        int multi = 1;
        do {
            if (currSum - multi * kplus >= 2 && numsMap.find(currSum - multi * kplus) != numsMap.end()) {
                return true;
            }
            multi++;
        } while (kplus != 0 && multi * kplus < currSum);

        numsMap[currSum]++;
    }

    return false;
}