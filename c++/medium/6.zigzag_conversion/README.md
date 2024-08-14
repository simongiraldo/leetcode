# 6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
P&nbsp;&nbsp;&nbsp;A&nbsp;&nbsp;&nbsp;&nbsp;H&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;N
A&nbsp;P&nbsp;L&nbsp;S&nbsp;&nbsp;&nbsp;I&nbsp;&nbsp;&nbsp;I&nbsp;&nbsp;&nbsp;G
Y&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;I&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows

## Examples

**Example 1:**

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"


**Example 2:**

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
> Explanation:
P&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;I&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;N
A&nbsp;&nbsp;&nbsp;L S&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;I G
Y A&nbsp;&nbsp;&nbsp;   H R
&nbsp;P&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;I


**Example 3:**

Input: s = "A", numRows = 1
Output: "A"