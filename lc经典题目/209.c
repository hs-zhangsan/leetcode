/*
    解题思路：
    本题给定一个含 n 个正整数的数组和一个正整数 s，
    要求在数组中找出连续子数组的和 ≥ s 且长度最小的连续子数组。
    这题我们可以通过滑动窗口的方法去解。

    滑动窗口解法：
    假设下标从 left 到 right 连续子数组元素和为 sum。
    如果当前的 sum 小于 target，则往下标 right 后面多加一个数组元素，并把这个数组元素也加入到 sum 中。
    （下标 right 后面的一个数组元素也纳入到 sum 中）
    依次类推，如果 sum 仍然小于 target，继续往下标 right 后面多加一个数组元素，
    直到最后 sum > target，就找到了一个满足题意的连续子数组，记录长度即可。
    然后再从下标 left 不断右移，缩小该连续子数组的和 sum。
    在将 left 不断右移过程中，到某一时刻 sum < target，
    此时 right 又开始不断右移，找到一个连续子数组的和 sum > target，依次类推。
    整个过程一直保持着一个窗口，其长度不是固定的，但是是被 left 和 right 这两个索引所定义的，
    窗口不停向前滑动去寻找满足题意的连续子数组。
*/

int minSubArrayLen(int target, int* nums, int numsSize){
    int sum = 0;               //  窗口中数组元素的和
    int ans = INT_MAX;         //  最小的连续子数组的长度
    int left = 0, right = -1;  //  nums[left...right] 为滑动窗口
    while (left < numsSize) {
        // sum 小于 s，窗口的右边界向前拓展，但要保证右边界 right 不越界
        if ((right < numsSize - 1) && (sum < target)) {
            sum += nums[++right];

        //  sum 大于等于 s，窗口的左边界向前行进
        } else {
            sum -= nums[left++];
        }

        //  找到可行的连续子数组，取 res 和目前连续子数组的长度（前闭右闭，长度 +1）的最小值
        if (sum >= target) {
            ans = fmin(ans, right - left + 1);
        }
    }

    // 不存在符合条件的子数组，则返回 0，否则返回最小的连续子数组的长度
    return ans == INT_MAX ? 0 : ans;
}