# [3719. Longest Balanced Subarray I](https://leetcode.com/problems/longest-balanced-subarray-i)

## 📝 Problem Statement
You are given an integer array `nums`.

A subarray is considered **balanced** if:
- The number of **distinct even elements** equals the number of **distinct odd elements**.

Return the length of the longest balanced subarray.

---

## 🚀 Approach

### 🔹 Brute Force Strategy
1. Fix a starting index `i`.
2. Expand the subarray to the right using index `j`.
3. Maintain two unordered sets:
   - `evens` → stores distinct even numbers
   - `odds` → stores distinct odd numbers
4. For every extension:
   - Insert the current number into the appropriate set.
   - If `evens.size() == odds.size()`, update the maximum length.

---

## ⏱ Complexity Analysis
- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💡 Key Insight
We track **distinct** even and odd numbers separately.  
Whenever their counts match, the current subarray is balanced.
