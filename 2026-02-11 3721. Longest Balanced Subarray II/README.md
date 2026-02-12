# [3721. Longest Balanced Subarray II](https://leetcode.com/problems/longest-balanced-subarray-ii)

## 📝 Problem Statement
You are given an integer array `nums`.

A subarray is considered **balanced** if:
- Each number appears at most once (no duplicates), and
- The number of even elements equals the number of odd elements.

Return the length of the longest balanced subarray.

---

## 🚀 Approach

### Key Ideas
1. Traverse from right to left.
2. Maintain:
   - A hashmap to ensure uniqueness (remove previous occurrence).
   - A segment tree to maintain:
     - Prefix sum
     - Minimum prefix
     - Maximum prefix
3. Treat:
   - Even number → `+1`
   - Odd number → `-1`
4. A balanced subarray means prefix sum equals `0`.

### Why Segment Tree?
The segment tree efficiently:
- Maintains range prefix sums
- Tracks min/max prefix
- Finds the farthest right index where prefix sum equals target (0)

This allows checking valid balanced subarrays in `O(log n)` per update.

---

## ⏱ Complexity Analysis
- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---

## 💡 Key Insight
Convert the problem into a prefix sum problem:
- Balanced ⇢ equal even & odd ⇢ total sum = 0  
Then use a segment tree to dynamically maintain prefix constraints while ensuring uniqueness.
