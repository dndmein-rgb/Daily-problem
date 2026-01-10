# 712. Minimum ASCII Delete Sum for Two Strings

## 📋 Problem Description
**Problem Number**: 712  
**Difficulty**: Medium  
**LeetCode Link**: [Minimum ASCII Delete Sum](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)  
**Pattern**: Dynamic Programming (String Comparison)

---

### Problem Statement
Given two strings `s1` and `s2`, return the lowest **ASCII sum** of deleted characters to make two strings equal.

---

## 💡 Approach: Dynamic Programming

This problem is a variation of the **Longest Common Subsequence (LCS)** or **Edit Distance**. Instead of counting the number of operations, we track the cost (ASCII value) of deletions.



### Key Logic
1. **Match**: If `s1[i] == s2[j]`, no deletion is needed. Move both pointers: `solve(i+1, j+1)`.
2. **Mismatch**: We have two choices:
   - Delete `s1[i]`: Cost is `ASCII(s1[i]) + solve(i+1, j)`.
   - Delete `s2[j]`: Cost is `ASCII(s2[j]) + solve(i, j+1)`.
   - Take the **minimum** of these two choices.
3. **Base Case**: If one string is empty, the cost is the sum of ASCII values of all remaining characters in the other string.

---

## ⚡ Complexity Analysis
* **Time Complexity**: $O(N \times M)$ — Every state $(i, j)$ is computed once.
* **Space Complexity**: $O(N \times M)$ — To store the DP table.

---
**Date Solved**: January 10, 2026
