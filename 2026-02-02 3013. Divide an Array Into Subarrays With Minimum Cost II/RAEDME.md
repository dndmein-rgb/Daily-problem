# [3013. Divide an Array Into Subarrays With Minimum Cost II](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii)

## Problem Statement
You are given an integer array `nums`, and integers `k` and `dist`.

You must divide the array into subarrays such that:
- Each subarray has length at most `dist`
- You pick exactly `k` elements in total (including `nums[0]`)
- The **cost** is the sum of the chosen elements

Return the **minimum possible cost**.

---

## Constraints
- 1 ≤ nums.length ≤ 10⁵
- 1 ≤ nums[i] ≤ 10⁹
- 1 ≤ k ≤ nums.length
- 1 ≤ dist ≤ nums.length

---

## Approach
- The first element `nums[0]` is always included.
- For the remaining elements, we must choose `k - 1` elements within a sliding window of size `dist`.
- Maintain:
  - `kMinimum`: the smallest `k - 1` elements in the current window
  - `remaining`: all other elements in the window
- Use two ordered sets to efficiently:
  - Insert new elements
  - Remove expired elements
  - Maintain the sum of the smallest `k - 1` elements
- Slide the window and update the minimum cost.

This is essentially a **sliding window + ordered set optimization** problem.

---

## Example
Input:
nums = [1,3,2,6,4,2]
k = 3
dist = 3


Output:
7


Explanation:
- Always include `nums[0] = 1`
- Optimal selection of remaining elements minimizes total sum

---

## Complexity Analysis
- Time Complexity: O(n log n)
- Space Complexity: O(n)
