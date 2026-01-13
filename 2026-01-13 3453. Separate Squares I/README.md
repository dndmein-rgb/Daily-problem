# 3453. Separate Squares I

## 📋 Problem Description
**Problem Number**: 3453  
**Difficulty**: Medium  
**LeetCode Link**: [Separate Squares I](https://leetcode.com/problems/separate-squares-i/)  
**Pattern**: Binary Search on Answer / Geometry

---

### Problem Statement
You are given a 2D integer array `squares` where `squares[i] = [xi, yi, li]` represents a square with its bottom-left corner at `(xi, yi)` and side length `li`.

Find the **minimum** y-coordinate of a horizontal line $y = y_{line}$ such that the total area of the squares above the line is **equal** to the total area of the squares below the line.

---

### 📝 Examples

**Example 1:**
* **Input**: `squares = [[0,0,1],[2,2,1]]`
* **Output**: `1.00000`
* **Explanation**: Total area is 2. The line $y=1$ leaves area 1 below and area 1 above.

**Example 2:**
* **Input**: `squares = [[0,0,2],[1,1,1]]`
* **Output**: `1.16667`

---

## 💡 Approach: Binary Search on Answer

The total area below a horizontal line $y = H$ is a **monotonically increasing function** of $H$. This makes the problem perfect for Binary Search.



### The Logic
1. **Define Range**: The line must lie between the lowest $y$ (`y`) and the highest $y$ (`y + l`) across all squares.
2. **Calculate Total Area**: Sum up $l_i^2$ for all squares.
3. **Check Function**: For a given `mid_y`, calculate the area of all parts of squares lying below it:
   - If `mid_y` is above the square: `area += l * l`.
   - If `mid_y` is below the square: `area += 0`.
   - If `mid_y` intersects the square: `area += (mid_y - y) * l`.
4. **Precision**: Since we need a decimal answer, we continue the binary search until the range is sufficiently small (e.g., $10^{-5}$) or for a fixed number of iterations (e.g., 100) to ensure high precision.



---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \cdot \log(\frac{Range}{\epsilon}))$ — where $N$ is the number of squares and $\epsilon$ is the required precision.
* **Space Complexity**: $O(1)$ — Only a few variables are used.

---
**Date Solved**: January 13, 2026
