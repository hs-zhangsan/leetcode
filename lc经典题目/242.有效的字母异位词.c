/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start


bool isAnagram(char * s, char * t){
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t) {
        return false;
    }

    int table[26];
    memset(table, 0, sizeof(table));
    for (int i = 0; i < len_s; i++) {
        table[s[i] - 'a']++;
        table[t[i] - 'a']--;
        
    }
    for (int i = 0; i < 26; i++) {
        if (table[i] != 0) {
            return false;
        }
    }
    
    return true;
}
// @lc code=end

