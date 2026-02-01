# [3010. Divide an Array Into Subarrays With Minimum Cost I](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)

## Problem Summary
You are given an integer array `nums`.

You must divide the array into **three subarrays** such that:
- The first subarray contains **only `nums[0]`**
- The remaining elements are divided into two other subarrays
- The cost of a subarray is its **minimum element**

Return the **minimum total cost** across all valid divisions.

---

## Key Insight
The first subarray is forced to be `{ nums[0] }`, so its cost is fixed.

To minimize the total cost:
- The other two subarrays should contribute the **two smallest values** from `nums[1…n-1]`

That’s it. No fancy partitioning. No DP. No sorting required.

---

## Approach
1. Keep two variables:
   - `second` → smallest element after index 0
   - `third` → second smallest element after index 0
2. Traverse the array from index `1`
3. Update `second` and `third` in one pass
4. Return:
nums[0] + second + third


---

## Complexity
- **Time:** O(n)
- **Space:** O(1)

Optimal and clean.

---

## Example
Input:
nums = [1, 2, 3, 12]


Explanation:
- First subarray: `{1}` → cost = 1
- Other two subarrays contribute `2` and `3`

Output:
6


---

## Common Pitfalls
- Sorting the array unnecessarily
- Overthinking the “subarray” wording
- Forgetting that `nums[0]` is locked into its own group

---

## Final Note
This problem is disguised as a partition problem but is actually a **simple greedy minimum-selection task**.

If your solution is longer than one loop, you missed the point.
