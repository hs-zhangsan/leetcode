/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子数组和
 */

// @lc code=start

/*
2022-01-07注释
int maxSubArray(int* nums, int numsSize){
    int ret = INT_MIN;
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ret = fmax(ret, sum);
        
        if (sum < 0) {
            sum = 0;
        }
    }

    return ret;
}
*/

struct Status {
    int lSum, rSum, mSum, iSum;
};

struct Status pushUp(struct Status l, struct Status r) {
    int iSum = l.iSum + r.iSum;
    int lSum = fmax(l.lSum, l.iSum + r.lSum);
    int rSum = fmax(r.rSum, r.iSum + l.rSum);
    int mSum = fmax(fmax(l.mSum, r.mSum), l.rSum + r.lSum);
    return (struct Status){lSum, rSum, mSum, iSum};
};

struct Status get(int* a, int l, int r) {
    if (l == r) {
        return (struct Status){a[l], a[l], a[l], a[l]};
    }
    int m = (l + r) >> 1;
    struct Status lSub = get(a, l, m);
    struct Status rSub = get(a, m + 1, r);
    return pushUp(lSub, rSub);
}

int maxSubArray(int* nums, int numsSize) {
    return get(nums, 0, numsSize - 1).mSum;
}
// @lc code=end
