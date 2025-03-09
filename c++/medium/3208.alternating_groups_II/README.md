# 3208. Alternating Groups II
There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

- colors[i] == 0 means that tile i is red.
- colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.





## Examples

**Example 1:**

Input: colors = [0,1,0,1,0], k = 3

Output: 3

> Explanation:

![image](https://github.com/user-attachments/assets/2cd9ac37-7c47-423f-a2b1-b87eb09b361e)
Alternating groups:
![image](https://github.com/user-attachments/assets/b3901a2d-c690-4be9-84ec-4c6356d5865c)
![image](https://github.com/user-attachments/assets/9be6f5a8-0a03-40da-a81a-b3c917d25972)
![image](https://github.com/user-attachments/assets/b20ae11f-c3c3-4a3e-910a-5dd6a958040c)



------------

**Example 2:**

Input: colors = [0,1,0,0,1,0,1], k = 6

Output: 2

> Explanation:

![image](https://github.com/user-attachments/assets/8cddce2b-cfe6-4d39-8bdd-7f363335f39c)
Alternating groups:
![image](https://github.com/user-attachments/assets/506090db-b648-4c69-b6e3-3c8b618118ee)
![image](https://github.com/user-attachments/assets/d5367231-e971-49a3-896e-40992edcaefa)

