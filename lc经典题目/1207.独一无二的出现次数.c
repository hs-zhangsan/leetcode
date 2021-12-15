/*
 * @lc app=leetcode.cn id=1207 lang=c
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start


bool uniqueOccurrences(int* arr, int arrSize){
    int hash[2001] = {0}, set[2001] = {0};
    for (int i = 0; i < arrSize; i++) {
        hash[arr[i] + 1000]++;
    }
    for (int i = 0; i < 2001; i++) {
        if (hash[i] > 0 && set[hash[i]] > 0) {
            return false;
        } else {
            set[hash[i]] = 1;
        }
    }
    
    return true;
}
// @lc code=end

