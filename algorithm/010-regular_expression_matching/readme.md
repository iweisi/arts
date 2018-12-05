# [正则表达式匹配](https://leetcode.com/problems/regular-expression-matching/solution/)
给一个字符串(`s`)和模式(`p`)，实现支持`'.'`和`'*'`的正则表达式匹配。
```
'.' 匹配任何单个字符
'*' 匹配0次或多次前面的元素
```
注意是整个字符串完全匹配(不是部分匹配)。

**注意：**  
- `s`可以为空或只包含小写字母的`a-z`
- `p`可以为空或只包含小写字母的`a-z`以及字符`'.'`或`'*'`

```
Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a"无法匹配整个字符串"aa".

Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*'意味着匹配0次或多次前面的字符'a'，'a'重复一次就变成了"aa".

Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*"代表"0次或多次(*) 任意字符(.)".

Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c可以重复0次 a刻意重复1次。所以能够匹配"aab".

Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
```
