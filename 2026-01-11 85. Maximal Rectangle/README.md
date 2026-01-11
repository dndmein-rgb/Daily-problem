# 85. Maximal Rectangle

## 📋 Problem Description
**Problem Number**: 85  
**Difficulty**: Hard  
**LeetCode Link**: [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)  
**Pattern**: Monotonic Stack (Histogram Variation)

---

### Problem Statement
Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return its area.

---

## 💡 Approach: Histogram Building

The core idea is to break the 2D matrix into multiple 1D "Largest Rectangle in Histogram" problems.



### Steps
1. **Row-by-Row Histogram**: We maintain a `heights` array. For each row:
   - If `matrix[i][j] == '1'`, we increment `heights[j]`.
   - If `matrix[i][j] == '0'`, we reset `heights[j]` to `0` (because a rectangle cannot be built through a zero).
2. **Apply Monotonic Stack**: For every row's updated `heights`, we find the maximum area possible using the **Nearest Smaller Element** logic to define the left and right boundaries for each bar.
3. **Global Maximum**: Track the maximum area found across all rows.



### Optimization
While the provided code uses two separate functions for `prev` and `next`, this can be optimized into a **single pass** monotonic stack to reduce constant time factors.

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times M)$ — Where $N$ is the number of rows and $M$ is the number of columns.
* **Space Complexity**: $O(M)$ — To store the histogram heights for the current row.

---
**Date Solved**: January 11, 2026
