# 🧮 Minimize Maximum Pair Sum in Array

- **Problem:** [LeetCode 1877 – Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/)

---

## 🧠 Problem Summary

You are given an array `nums` of even length.

In each operation:
- Pair up all elements such that each element is used exactly once
- The **pair sum** is the sum of the two elements in a pair

Your task:
- Minimize the **maximum pair sum**
- Return that minimized maximum value

---

## 💡 Core Insight

If you pair:
- **smallest with largest**
- second smallest with second largest
- and so on

You balance the sums.

Any other pairing makes at least one pair worse.

This is a classic **greedy + sorting** problem.

---

## 🚀 Approach

1. Sort the array
2. Use two pointers:
   - `i` at the start
   - `j` at the end
3. Pair `nums[i] + nums[j]`
4. Track the maximum among all pair sums
5. Return it

---

## 🛠️ Algorithm

- Sort `nums`
- Initialize two pointers
- Compute max of paired sums

---

## ⏱️ Complexity

- **Time:** `O(n log n)` due to sorting
- **Space:** `O(1)` extra space (ignoring sort internals)

---

## ⚠️ Common Mistakes

- Pairing adjacent elements after sorting
- Forgetting the array length is guaranteed even
- Overthinking with heaps or DP

This problem is simpler than it looks. Trust the greedy.

---

## 🎯 Takeaway

This is a textbook example of:
- Greedy strategy
- Pairing extremes to minimize worst-case outcome

If this felt hard, the issue isn’t C++. It’s recognizing patterns early.
