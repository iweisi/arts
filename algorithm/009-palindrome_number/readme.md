# [数字回文](https://leetcode.com/problems/palindrome-number/solution/)
检查一个整型数字是否为回文。如果一个数字正着读/反着读都一样，它就是回文。

```
Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
解释: 从左到右读做-121，但从右到左就变成了121-，所以不是回文。

Example 3:
Input: 10
Output: false
解释: 从右到左读01(零一)，从左到右读10(十)所以不是回文。
```

**哥们儿看这里：**  
有种你别把它转换为字符串再做判断啊！

## 我的思路
这就是道送分题，和007、008两题的思路一样，都是整型反转，这道题无非就是反转后和输入参数比较是否相等。不过有个灰常微妙的地方，我提交后暴击率88%，仔细研究一番发现确实还有优化空间，即没必要全部反转完，每反转一步就检查下值是否大于输入参数。如果已经大了，就根本不可能是回文，提前结束判断。
```c
bool isPalindrome(int x) {
  int forward = x;
  int backward = 0;

  if (x < 0) return 0; // false

  while (x) { // 判断条件还可以优化
    backward = (backward * 10) + (x % 10);
    x /= 10;
  }

  return forward == backward;
}
```