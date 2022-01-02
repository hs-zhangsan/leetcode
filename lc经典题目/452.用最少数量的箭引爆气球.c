/*
 * @lc app=leetcode.cn id=452 lang=c
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
int cmp(void *a, void *b)
{
    return ((*((int**)a))[0] > (*((int**)b))[0]);
} 

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    qsort(points, pointsSize, sizeof(points[0]),cmp);
    
    int arrowNum = 1;
    for(int i = 1; i < pointsSize; i++) {
        if(points[i][0] > points[i-1][1])
            arrowNum++;
        else
            points[i][1] = points[i][1] > points[i-1][1] ? points[i-1][1] : points[i][1];
    }
    return arrowNum;
}
// @lc code=end

