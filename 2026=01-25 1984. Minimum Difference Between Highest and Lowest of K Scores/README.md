# 📉 Minimum Difference Between Highest and Lowest of K Scores

- **Problem:** [LeetCode 1984 – Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores)

---

## 🧠 Problem Summary

You are given an array `nums` representing scores and an integer `k`.

Select **any `k` elements** such that the **difference between the maximum and minimum** of those elements is minimized.

Return that minimum difference.

---

## 💡 Key Observation

Once the array is sorted:

- Any group of `k` consecutive elements forms a valid candidate
- The difference is simply:
  
nums[i + k - 1] - nums[i]


No fancy data structures. No DP. Just discipline.

---

## 🚀 Approach 1: Sort + Sliding Window (Recommended)

### Steps
1. Sort `nums` in ascending order
2. Slide a window of size `k`
3. Track the minimum difference

### Code Idea
- Simple
- Readable
- Optimal

### Complexity
- **Time:** `O(n log n)`
- **Space:** `O(1)`

---

## 🔄 Approach 2: Reverse Sort + Two Pointers

### Why it exists
- Demonstrates the same logic using a different traversal style
- Educational, not necessary

### Downsides
- Harder to read
- Same complexity, more moving parts

---

## ⚠️ Common Mistakes

- Forgetting `k == 1` ⇒ answer is always `0`
- Overcomplicating with heaps or prefix arrays
- Using absolute difference without sorting
- Thinking contiguous means original indices (it doesn’t)

---

## 🎯 Takeaway

This problem tests:
- Sorting intuition
- Window mechanics
- Knowing when **simple is optimal**

If you struggled here, the issue isn’t sliding windows.
It’s resisting the urge to over-engineer.
