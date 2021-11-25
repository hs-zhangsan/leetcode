/*
    滑动窗口算法详解略。

    一旦当前字符 s[i] 在 Hash 已经存在映射，说明当前的字符已经出现过了。
    而若 index[s[i]] > left 成立，说明之前出现过的字符在窗口内，
    那么如果要加上当前这个重复的字符，就要移除之前的那个。
    所以让 left 赋值为 index[s[i]]，由于 left 是窗口左边界的前一个位置
    （这也是 left 初始化为 -1 的原因，因为窗口左边界是从0开始遍历的），
    所以相当于已经移除出滑动窗口了。
    ASCII 表共能表示 256 个字符，但是由于键盘只能表示 128 个字符，所以用 128 也行。
    然后全部初始化为 -1，这样的好处是不用查找当前字符是否存在映射对了。
    对于每一个遍历到的字符，直接用其在数组中的值来更新 left。
    因为默认是 -1，而 left 初始化也是 -1，所以并不会产生错误，这样就省了 if 判断的步骤。
*/

int lengthOfLongestSubstring(char * s){
    int index[128];
    for (int i = 0; i < 128; i++) {
        index[i] = -1;
    }

    int left = -1;
    int len = strlen(s);
    if (len == 1) {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (index[s[i]] > left) {
            left = index[s[i]];
        }
        if (ans < i - left) {
            ans = i - left;
        }
        index[s[i]] = i;
    }

    return ans;
}