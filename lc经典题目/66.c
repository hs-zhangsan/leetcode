/*
思路:
 当我们对数组 \textit{digits}digits 加一时，我们只需要关注 \textit{digits}digits 
 的末尾出现了多少个 99 即可。我们可以考虑如下的三种情况：
 如果 \textit{digits}digits 的末尾没有 99，例如 [1, 2, 3][1,2,3]，那么我们直接将
 末尾的数加一，得到 [1, 2, 4][1,2,4] 并返回；
 如果 \textit{digits}digits 的末尾有若干个 99，例如 [1, 2, 3, 9, 9][1,2,3,9,9]，
 那么我们只需要找出从末尾开始的第一个不为 99 的元素，即 33，将该元素加一，得到 
 [1, 2, 4, 9, 9][1,2,4,9,9]。随后将末尾的 99 全部置零，得到 [1, 2, 4, 0, 0][1,2,4,0,0] 并返回。
 如果 \textit{digits}digits 的所有元素都是 99，例如 [9, 9, 9, 9, 9][9,9,9,9,9]，
 那么答案为 [1, 0, 0, 0, 0, 0][1,0,0,0,0,0]。我们只需要构造一个长度比 \textit{digits}digits 
 多 11 的新数组，将首元素置为 11，其余元素置为 00 即可。
算法:
 只需要对数组 \textit{digits}digits 进行一次逆序遍历，找出第一个不为 99 的元素，
 将其加一并将后续所有元素置零即可。如果 \textit{digits}digits 中所有的元素均为 99，
 那么对应着「思路」部分的第三种情况，我们需要返回一个新的数组。
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for (int i = digitsSize - 1; i >= 0; i--){
        if (digits[i] == 9){
            digits[i] = 0;
        } else{
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    *returnSize = digitsSize + 1;

    int *ret = (int*)malloc(sizeof(int)*(digitsSize + 1));
    memset(ret, 0, sizeof(int)*(digitsSize + 1));
    ret[0] = 1;
    return ret;
}