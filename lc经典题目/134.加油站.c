/*
 * @lc app=leetcode.cn id=134 lang=c
 *
 * [134] 加油站
 */

// @lc code=start
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int curSum = 0, min = INT_MAX;
    int i;
    for (i = 0; i < gasSize; i++) {
        int diff = gas[i] - cost[i];
        curSum += diff;
        if (curSum < min) {
            min = curSum;
        }
    }
    if (curSum < 0) {
        return -1;
    }
    if (min >= 0) {
        return 0;
    }
    for (i = gasSize - 1; i >= 0; i--) {
        min += (gas[i] - cost[i]);
        if (min >= 0) {
            return i;
        }
    }
    return 0;
}
// @lc code=end

