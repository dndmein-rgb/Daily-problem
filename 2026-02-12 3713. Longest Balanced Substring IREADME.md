# [3713. Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i)

## Problem Statement
You are given a lowercase string `s`.

A substring is called **balanced** if all characters that appear in it have the **same frequency**.

Return the length of the longest balanced substring.

---

## Constraints
- 1 ≤ s.length ≤ 10⁵
- `s` consists of lowercase English letters

---

## Approach
- Fix a starting index `i`.
- Expand the substring to the right using index `j`.
- Maintain a frequency array of size 26.
- For every extension:
  - Update the frequency of the current character.
  - Check whether all non-zero frequencies are equal.
- If valid, update the maximum length.

This brute-force approach checks every substring.

---

## Complexity Analysis
- **Time Complexity:** O(26 × n²) ≈ O(n²)
- **Space Complexity:** O(1)

---

## Key Insight
A substring is balanced if every character present appears the same number of times.  
We verify this by ensuring all non-zero frequencies match a single target frequency.
