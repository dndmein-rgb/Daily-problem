# [3634. Minimum Removals to Balance Array](https://leetcode.com/problems/minimum-removals-to-balance-array)

## Problem Statement
You are given an integer array `nums` and an integer `k`.

An array is considered **balanced** if for every pair of elements `(a, b)` in the array:
max(a, b) ≤ k × min(a, b)


You may remove any number of elements from the array.  
Return the **minimum number of removals** required to make the array balanced.

---

## Constraints
- 1 ≤ nums.length ≤ 10⁵
- 1 ≤ nums[i] ≤ 10⁹
- 1 ≤ k ≤ 10⁹

---

## Approach
1. **Sort the array** to enable range-based validation.
2. Use a **two-pointer sliding window**:
   - Pointer `i` represents the smallest element in the current window.
   - Pointer `j` expands forward while `nums[j] ≤ nums[i] × k`.
3. The window `[i, j)` is a valid balanced subarray.
4. Elements outside this window must be removed.
5. Minimize removals across all valid windows.

This avoids repeated binary searches by ensuring `j` only moves forward, making the solution efficient.

---

## Example
**Input**
nums = [1, 3, 6, 10]
k = 2


**Output**
1


**Explanation**
Removing `10` results in `[1, 3, 6]`, which satisfies the balance condition.

---

## Complexity Analysis
- **Time Complexity:** O(n log n)
  - Sorting: O(n log n)
  - Two-pointer scan: O(n)
- **Space Complexity:** O(1) extra space (excluding sort)

---

## Key Insight
After sorting, the balance condition depends only on the smallest element in the window.  
Using a sliding window ensures each element is processed once, making this approach optimal.
