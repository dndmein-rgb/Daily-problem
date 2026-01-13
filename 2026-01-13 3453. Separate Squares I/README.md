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
### 📊 Visual Representation (Example 1)
**Input**: `squares = [[0,0,1],[2,2,1]]`

```text
  y ^
    |
  3 |       +-------+ <--- top (y+l=3)
    |       |  SQ 2 |
  2 |       +-------+ <--- bottom (y=2)
    |
  1 | - - - - - - - - - - - - - - -  y = 1.0 (Target Line)
    |
    |   +---+ <--- top (y+l=1)
  0 |   |SQ1|
____+___+---+__________________________> x
    |   0   1       2       3

---

## 💡 Approach: Binary Search on Answer

The total area below a horizontal line $y = H$ is a **monotonically increasing function**. As the line moves up, the area below it can only increase or stay the same. This monotonicity allows us to use **Binary Search**.

### 1. Visualizing the Split
The line $y = y_{line}$ can cut through squares, sit above them, or sit below them. We need to sum these partial areas.



### 2. The `check(mid_y)` Logic
For every square $i$ with bottom $y_i$ and top $y_i + l_i$:
* **Case 1: Line is above square** ($y_{line} \ge y_i + l_i$)
    * Add full area: $l_i \times l_i$.
* **Case 2: Line cuts through square** ($y_i < y_{line} < y_i + l_i$)
    * Add partial area: $(y_{line} - y_i) \times l_i$.
* **Case 3: Line is below square** ($y_{line} \le y_i$)
    * Add nothing: $0$.



### 3. Binary Search Range
* **Low**: The minimum $y$ among all squares.
* **High**: The maximum $y + l$ among all squares.
* **Termination**: Since we need a double, we run the loop for a fixed number of iterations (e.g., 100) to guarantee a precision of $10^{-15}$.

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \cdot \log(\text{Range}/\epsilon))$ — We perform $N$ calculations for each of the 100 iterations.
* **Space Complexity**: $O(1)$ — No extra data structures used.

---
**Date Solved**: January 13, 2026
