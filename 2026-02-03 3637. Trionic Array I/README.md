# [3637. Trionic Array I](https://leetcode.com/problems/trionic-array-i)

## Problem Statement

You are given an integer array `nums`.

An array is called **trionic** if it consists of **three consecutive monotonic segments** arranged as:

1. Strictly increasing
2. Strictly decreasing
3. Strictly increasing

All adjacent elements must be distinct.

Return `true` if the array is trionic, otherwise return `false`.

---

## Constraints

- 4 ≤ nums.length ≤ 10⁵
- -10⁹ ≤ nums[i] ≤ 10⁹
- All adjacent elements must be compared strictly

---

## Approach

This solution tracks **direction changes** while iterating through the array.

### Key Ideas

- A boolean `increasing` represents the current trend.
- A counter `count` tracks how many times the trend changes.
- The array must:
  - Start with an increasing trend
  - Never contain equal adjacent elements
  - Switch direction exactly **three times** to form:
    - increasing → decreasing → increasing

### Logic Breakdown

1. If the first step is decreasing, the array is invalid.
2. Traverse the array from left to right.
3. If two adjacent elements are equal, return `false`.
4. Whenever the direction changes:
   - Flip the `increasing` flag
   - Increment the transition counter
5. At the end, return `true` only if exactly **three transitions** occurred.

---

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Example

**Input**
nums = [1, 3, 5, 4, 2, 6, 8]


**Explanation**

- Increasing: 1 → 3 → 5  
- Decreasing: 5 → 4 → 2  
- Increasing: 2 → 6 → 8  

Exactly three direction transitions detected.

**Output**
true


---

## Notes

- This implementation relies on counting direction flips rather than explicitly tracking segments.
- Correctness depends on the assumption that exactly three monotonic transitions impl
