# 1895. Largest Magic Square

## 📋 Problem Description
**Difficulty**: Medium  
**LeetCode Link**: [Largest Magic Square](https://leetcode.com/problems/largest-magic-square/)  
**Pattern**: Prefix Sum + Brute Force Validation  

A **magic square** is a square subgrid where:
- All rows have the same sum  
- All columns have the same sum  
- Both diagonals have the same sum  

Given a grid of integers, return the **size of the largest magic square** inside it.

---

## 🧠 Intuition

A naive solution would recompute sums repeatedly and time out.

Instead:
- Precompute **row prefix sums** and **column prefix sums**
- This allows O(1) row/column sum queries
- Try square sizes from **largest to smallest** so we can exit early

The first valid square we find is the answer.

---

## 🛠️ Approach

1. Build prefix sums for every row and column
2. Iterate square sizes from `min(rows, cols)` down to `2`
3. For each top-left position:
   - Fix the target sum using the first row
   - Verify all rows match the target
   - Verify all columns match the target
   - Verify both diagonals
4. Return the first valid size found
5. If nothing works, return `1` (single cell is always magic)

---

## ⏱️ Complexity Analysis

- **Time Complexity**: `O(min(R, C)² × R × C)`  
- **Space Complexity**: `O(R × C)`  

Given constraints (`R, C ≤ 50`), this comfortably passes.

---

## ⚠️ Common Mistakes

- Forgetting that diagonals cannot be optimized with prefix sums
- Checking smaller squares first and wasting time
- Recomputing row/column sums repeatedly instead of caching
- Assuming size `1` needs validation (it doesn’t)

---

## ✅ Key Takeaways

- Prefix sums turn brute force into something practical
- Early exit matters more than micro-optimizations
- Clean structure beats clever code in grid problems

---

## 📌 Final Note

This problem looks harder than it is.  
Once prefix sums are in place, it becomes systematic and predictable.

That’s the real win.
