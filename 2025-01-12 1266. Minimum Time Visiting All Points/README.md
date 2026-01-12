# 1266. Minimum Time Visiting All Points

## 📋 Problem Description
**Problem Number**: 1266  
**Difficulty**: Easy  
**LeetCode Link**: [Minimum Time Visiting All Points](https://leetcode.com/problems/minimum-time-visiting-all-points/)  
**Pattern**: Geometry / Chebyshev Distance

---

### Problem Statement
On a 2D plane, there are `n` points with integer coordinates `points[i] = [xi, yi]`. Your goal is to visit all the points in order.

You can move according to these rules:
* In **1 second**, you can move vertically, horizontally, or **diagonally** (i.e., move one unit vertically and one unit horizontally in one second).
* You must visit the points in the same order as they appear in the array.

Return the **minimum time** in seconds to visit all the points.

---

## 💡 Approach: Chebyshev Distance

The key to this problem is understanding the "diagonal move" rule. Since a diagonal move allows us to cover distance in both the $X$ and $Y$ directions simultaneously for the same cost (1 second), the time taken between two points is not the Manhattan distance ($dx + dy$), but the **Chebyshev distance**.



### Logic
1. To move from $(x_1, y_1)$ to $(x_2, y_2)$:
   - Calculate $dx = |x_2 - x_1|$
   - Calculate $dy = |y_2 - y_1|$
2. You can move diagonally for $\min(dx, dy)$ seconds. This reduces both $dx$ and $dy$ to zero for one of the axes.
3. The remaining distance is covered in straight horizontal or vertical lines.
4. Mathematically, this simplifies to just $\max(dx, dy)$.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N)$ — We traverse the list of points exactly once.
* **Space Complexity**: $O(1)$ — No additional data structures are required.

---
**Date Solved**: January 12, 2026
