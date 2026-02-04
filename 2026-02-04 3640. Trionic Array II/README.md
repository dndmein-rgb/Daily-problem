# [3640. Trionic Array II](https://leetcode.com/problems/trionic-array-ii)

## Problem Statement
You are given an integer array `nums`.  
A **trionic subsequence** is defined as a subsequence that follows **three consecutive trends**:

1. Strictly increasing
2. Strictly decreasing
3. Strictly increasing

Your task is to find the **maximum possible sum** of elements of any trionic subsequence in the array.  
If no such subsequence exists, return a very small value (handled implicitly by the algorithm).

---

## Constraints
- 1 ≤ nums.length ≤ 10⁵  
- −10⁹ ≤ nums[i] ≤ 10⁹  
- The subsequence must respect the original order of elements  
- Each trend must be **non-empty**  

---

## Approach
This problem is solved using **Dynamic Programming with Memoization**.

### State Definition
`dp[i][trend]` = maximum sum achievable starting at index `i` with current trend state:
- `0` → not started
- `1` → increasing
- `2` → decreasing
- `3` → increasing again (final phase)

### Transitions
- You may **skip elements** only before starting the first trend
- Based on the comparison between `nums[i]` and `nums[i+1]`, you either:
  - Continue the current trend
  - Transition to the next trend
- Once all three trends are completed, you may keep extending the final increasing phase

Invalid transitions return a very small negative value to prune bad paths.

---

## Example
**Input**
nums = [1, 3, 5, 4, 2, 6, 8]


**Output**
29


**Explanation**
A valid trionic subsequence is:
1 → 3 → 5 → 4 → 2 → 6 → 8


Sum = 29

---

## Complexity Analysis
- **Time Complexity:** O(n × 4) ≈ O(n)
- **Space Complexity:** O(n × 4) for memoization

---

## Key Insight
The difficulty is not detecting the trionic pattern, but **maximizing the sum while enforcing strict trend transitions**.  
The trend-based DP state cleanly encodes the rules without backtracking or brute for
