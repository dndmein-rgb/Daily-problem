# 1653. Minimum Deletions to Make String Balanced

## Problem Statement
You are given a string `s` consisting only of the characters `'a'` and `'b'`.  
A string is considered **balanced** if there is no index `i < j` such that `s[i] = 'b'` and `s[j] = 'a'`.

Return the **minimum number of deletions** needed to make the string balanced.

---

## Constraints
- `1 ≤ s.length ≤ 10^5`
- `s[i]` is either `'a'` or `'b'`

---

## Approach
- Count the total number of `'a'` characters to the right of each position.
- Traverse the string from left to right:
  - Keep track of how many `'b'` characters have appeared on the left.
  - At each position, compute deletions as:
    - delete all `'b'` on the left **or**
    - delete all `'a'` on the right
- Take the minimum possible deletions across all positions.

This efficiently finds the optimal split point.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Example
Input: s = "aababbab"
Output: 2
