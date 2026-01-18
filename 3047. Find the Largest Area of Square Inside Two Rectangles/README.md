# 3047. Find the Largest Area of Square Inside Two Rectangles

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode Link**: [Find the Largest Area of Square Inside Two Rectangles](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/)  
**Pattern**: Geometry + Rectangle Intersection

You are given two arrays `bottomLeft` and `topRight`, where each pair `bottomLeft[i] = [x1, y1]` and `topRight[i] = [x2, y2]` represents a rectangle with sides parallel to the axes.  

Your task is to find the **largest possible square area** that can be formed **inside the overlapping region of any two rectangles**.  

If no two rectangles overlap, return `0`.

---

## 🧪 Examples

### Example 1
**Input**  
bottomLeft = [[1,1],[2,2],[3,1]]  
topRight = [[3,3],[4,4],[6,6]]  

**Output**  
1  

**Explanation**: The first two rectangles overlap in a `1 × 1` region. The largest square that fits has side `1`, so area = `1`.

### Example 2
**Input**  
bottomLeft = [[1,1],[2,2]]  
topRight = [[3,3],[4,4]]  

**Output**  
1

### Example 3
**Input**  
bottomLeft = [[1,1],[3,3]]  
topRight = [[2,2],[4,4]]  

**Output**  
0  

**Explanation**: The rectangles only touch at the boundary. No overlapping area → no square.

---

## 🧠 Intuition
A square can only exist **inside the intersection of two rectangles**. Strategy:  

1. Take every pair of rectangles  
2. Compute their overlapping region  
3. If overlap exists:  
   - Largest square side = `min(overlap width, overlap height)`  
4. Track the maximum square area

No DP, no graph, just brute-force geometry.

---

## 📐 Intersection Computation
For rectangles `i` and `j`:

left = max(x1_i, x1_j)  
right = min(x2_i, x2_j)  
bottom = max(y1_i, y1_j)  
top = min(y2_i, y2_j)

Overlap exists if:  
right > left AND top > bottom

Square side:  
side = min(right - left, top - bottom)

Area:  
side * side

---

## ⏱️ Complexity
- **Time**: `O(n²)` for all rectangle pairs  
- **Space**: `O(1)` constant extra

---

## ❌ Common Mistakes
- Treating touching edges as overlap  
- Using `max(width, height)` instead of `min`  
- Returning side length instead of area  
- Overcomplicating with sweep-line or DP

---

## 📁 Folder Structure
3047-find-the-largest-area-of-square-inside-two-rectangles/  
├── 3047-find-the-largest-area-of-square-inside-two-rectangles.cpp  
└── README.md

---

## 🎯 Key Takeaway
Correct rectangle intersection → problem solved. Arithmetic only after that.
