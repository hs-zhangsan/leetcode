/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
bool isAnagram(char * s, char * t){
    int record[26] = {0};
    int lenS = strlen(s);
    int lenT = strlen(t);
    for (int i = 0; i < lenS; i++) {
        record[s[i] - 'a']++;
    }
    for (int i = 0; i < lenT; i++) {
        record[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) {
            return false;
        }
    }
    return true;
}
// @lc code=end

