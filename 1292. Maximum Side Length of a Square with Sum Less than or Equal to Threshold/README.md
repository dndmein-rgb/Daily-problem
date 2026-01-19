# 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

**Problem Link:** [LeetCode – Maximum Side Length of a Square with Sum ≤ Threshold](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/)

---

## 🧠 Core Idea

We need the **largest square submatrix** whose **sum ≤ threshold**.

Brute force dies immediately because:
- Checking all squares is O(n³)
- Constraints go up to 300×300

So we use two classic weapons:
1. **2D Prefix Sum** → O(1) square sum queries
2. **Binary Search on Side Length** → Efficient growth check

---

## 🧮 Prefix Sum Formula

Let `pref[i][j]` be sum of submatrix `(1,1) → (i,j)`

Sum of square with top-left `(i,j)` and side `k`:

