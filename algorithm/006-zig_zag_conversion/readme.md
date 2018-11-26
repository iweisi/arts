# [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/solution)

将字符串“PAYPALISHIRING”通过指定行数的曲线纹理的方式转换如下：
```
P   A   H   N
A P L S I I G
Y   I   R
```
此时连起来读成："PAHNAPLSIIGYIR"

实现下面的函数，将给定的字符串和行数作为参数进行转换：  
`string convert(string s, int numRows);`
```


Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

解释:
P     I    N
A   L S  I G
Y A   H R
P     I
```