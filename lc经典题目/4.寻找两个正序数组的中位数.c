/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    //先升序合并两数组
    int p1 = 0, p2 = 0;
    int sorted[nums1Size + nums2Size];
    int cur;
    while (p1 < nums1Size || p2 < nums2Size) {
        if (p1 == nums1Size) {
            cur = nums2[p2++];
        } else if (p2 == nums2Size) {
            cur = nums1[p1++];
        } else if (nums1[p1] < nums2[p2]) {
            cur = nums1[p1++];
        } else {
            cur = nums2[p2++];
        }
        sorted[p1 + p2 - 1] = cur;
    }

    //再根据数组长度的奇偶求中位数
    int n = nums1Size + nums2Size;
    double mid;
    if (n % 2 == 0) {
        mid = ((double)sorted[n / 2] + (double)sorted[(n / 2) - 1]) / 2;
    } else {
        mid = sorted[n / 2];
    }

    return mid;
}
// @lc code=end

