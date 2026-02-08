# [1653. Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced)

## Problem Statement
You are given a string `s` consisting only of characters `'a'` and `'b'`.

A string is considered **balanced** if there is no pair of indices `(i, j)` such that:
- `i < j`
- `s[i] = 'b'` and `s[j] = 'a'`

Return the **minimum number of deletions** needed to make the string balanced.

---

## Constraints
- `1 <= s.length <= 10^5`
- `s[i]` is either `'a'` or `'b'`

---

## Approach
- Count how many `'a'` characters exist to the **right** of each index.
- Traverse the string from left to right:
  - Keep track of how many `'b'` characters are seen so far.
  - At each position, calculate deletions needed as:
    - delete all previous `'b'` OR
    - delete all future `'a'`
- Take the minimum across all positions.

This ensures an optimal split where all `'a'` come before `'b'`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`
