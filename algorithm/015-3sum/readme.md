# [Two Num](https://leetcode.com/problems/two-sum)
给一个整数构成的数组，其中有三个元素`a,b,c`的总和为0，即`a+b+c=0`？找出数组中唯一的和为零的三个数。

**注意**：答案中是一套集合且其中不能有重复。
```
Example:
数组定义 nums = [-1, 0, 1, 2, -1, -4],

结果集合:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

## 我的思路一、穷举
似乎所有算法题都可以用穷举这种笨办法，我刚开始却没什么好的思路，但由于题目本身的限制，即使用穷举也不简单，所以大概说一下思路，首先需要注意题意：
1. 要找出全部相加为0的组合，所以需要注意二维数组的分配
2. 全部组合中要“去重”，就是说`[0, -1, 1]`和`[-1, 0, 1]`这两个组合应该被看作一个

留意这两个限制之后，其实解题思路就不难了：
1. 三层for循环嵌套，遍历每种组合的和是否为0
2. 发现相加为0的组合后，做一次排序，并存到结果数组中
3. 遍历当前的结果数组，查看是否存在重复

下面的代码不全，因为我觉得意义不大，因为做得不够严谨，其次O(n³)的时间复杂度根本无法通过leetcode的时间限制，所以就算逻辑对了，提交也不通过。
```c
int** threeSum(int* nums, int numsSize, int* returnSize) {
  int** results = calloc(numsSize * 3, sizeof(int*));
  int len = 0;

  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      for (int k = j + 1; k < numsSize; k++) {
        // 检查是否符合三值和为零
        if (nums[i] + nums[j] + nums[k]) {
          continue;
        }

        // 将三个值排序
        int min = ...
        int mid = ...
        int max = ...
        
        // 去重
        int equal = 0;
        for (int l = 0; l < len; l++) {
          if (min == results[l][0] && max == results[l][2]) {
            equal = 1;
          }
        }
        if (equal) {
          continue;
        }

        // 赋值
        results[len] = calloc(3, sizeof(int));
        ...
        len++;
      }
    }
  }

  *returnSize = len;
  return results;
}
```
- 时间复杂度： O(n³)，三层for的悲剧
- 空间复杂度： O(n³)，最坏情况下