# [3379. Transformed Array](https://leetcode.com/problems/transformed-array)

## Problem Statement
You are given an integer array `nums` of length `n`.

Construct a new array `result` of the same length such that for each index `i`:
- If `nums[i]` is positive, move forward `nums[i]` steps from index `i`
- If `nums[i]` is negative, move backward `|nums[i]|` steps from index `i`
- Index movement is **circular**

Set:
result[i] = nums[(i + nums[i]) mod n]


Return the transformed array.

---

## Constraints
- 1 ≤ n ≤ 10⁵
- −10⁵ ≤ nums[i] ≤ 10⁵
- Circular indexing is required

---

## Approach
1. Iterate through each index `i`.
2. Compute the target index using circular arithmetic:
idx = (i + nums[i]) % n

3. Handle negative indices by adding `n` if needed.
4. Assign `result[i] = nums[idx]`.

This ensures correct wrap-around behavior for both positive and negative shifts.

---

## Example
**Input**
nums = [3, -2, 1, 0]


**Output**
[0, 1, -2, 0]


**Explanation**
- i = 0 → move 3 steps → index 3 → nums[3] = 0
- i = 1 → move -2 steps → index 3 → nums[3] = 0
- i = 2 → move 1 step → index 3 → nums[3] = 0
- i = 3 → move 0 steps → index 3 → nums[3] = 0

---

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

---

## Key Insight
Correct handling of **negative modulo** is essential.  
Always normalize indices into the range `[0, n-1]` to avoid out-of-bounds access.
