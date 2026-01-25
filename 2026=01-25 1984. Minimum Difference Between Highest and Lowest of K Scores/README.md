# 📉 Minimum Difference Between Highest and Lowest of K Scores

- **Problem:** [LeetCode 1984 – Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores)

---

## 🧠 Problem Summary

You are given an integer array `nums` representing scores and an integer `k`.

Choose **any `k` elements** from the array such that the **difference between the maximum and minimum** among those `k` elements is minimized.

Return that minimum difference.

---

## 🧪 Examples

### Example 1
Input: nums = [90], k = 1
Output: 0

**Explanation:**  
Only one score is chosen. Max − Min = 0.

---

### Example 2
Input: nums = [9,4,1,7], k = 2
Output: 2

**Explanation:**  
Sorted array → `[1,4,7,9]`  
Possible pairs:
- (1,4) → diff = 3  
- (4,7) → diff = 3  
- (7,9) → diff = 2 ✅  

Minimum difference is **2**.

---

## 📌 Constraints

- `1 <= k <= nums.length <= 1000`
- `0 <= nums[i] <= 10^5`

---

## 💡 Key Observation

After sorting the array:

- Any **group of `k` consecutive elements** forms a valid candidate
- The difference is simply:

nums[i + k - 1] - nums[i]


There is no benefit in picking non-consecutive elements once sorted. If you think otherwise, you’re wrong.

---

## 🚀 Approach 1: Sort + Sliding Window (Recommended)

### Steps
1. Sort `nums` in ascending order
2. Slide a window of size `k`
3. Track the minimum difference

### Complexity
- **Time:** `O(n log n)`
- **Space:** `O(1)`

---

## 🔄 Approach 2: Reverse Sort + Two Pointers

### Why it exists
- Demonstrates the same logic with a different traversal
- Useful for learning window mechanics

### Reality check
- Harder to read
- Same complexity
- No advantage over Approach 1

---

## ⚠️ Common Mistakes

- Forgetting `k == 1` → answer is always `0`
- Overengineering with heaps or prefix arrays
- Using absolute difference without sorting
- Thinking elements must be contiguous in the original array

---

## 🎯 Takeaway

This problem is not about clever tricks.

It tests:
- Sorting intuition
- Window discipline
- Knowing when **simple beats clever**

If this felt hard, the gap is fundamentals, not intelligence.
