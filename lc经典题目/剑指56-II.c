/*
    哈希表

    我们可以使用哈希映射统计数组中每个元素的出现次数。
    对于哈希映射中的每个键值对，键表示一个元素，值表示其出现的次数。
    在统计完成后，我们遍历哈希映射即可找出只出现一次的元素。
*/

struct HashTable {
    int key, val;
    UT_hash_handle hh;
};

int singleNumber(int *nums, int numsSize) {
    struct HashTable *hashTable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct HashTable *tmp;
        HASH_FIND_INT(hashTable, &nums[i], tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = nums[i];
            tmp->val = 1;
            HASH_ADD_INT(hashTable, key, tmp);
        } else {
            tmp->val++;
        }
    }
    int ans = 0;
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, hashTable, iter, tmp) {
        if (iter->val == 1) {
            ans = iter->key;
            break;
        }
    }
    return ans;
}