# 3047. Find the Largest Area of Square Inside Two Rectangles

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode Link**: [Find the Largest Area of Square Inside Two Rectangles](https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/)  
**Pattern**: Geometry + Rectangle Intersection

---

## 🧠 Intuition

A square can only exist where **two rectangles overlap**.

So instead of fantasizing about all squares:
- Pick every pair of rectangles
- Compute their intersection
- The biggest square that fits inside the intersection is limited by  
  `min(overlap width, overlap height)`

That’s it. Geometry, not wizardry.

---

## 📐 Intersection Computation

For rectangles `i` and `j`:

- `left   = max(x1_i, x1_j)`
- `right  = min(x2_i, x2_j)`
- `bottom = max(y1_i, y1_j)`
- `top    = min(y2_i, y2_j)`

If:
- `right > left`
- `top > bottom`

Then overlap exists.

Square side:
