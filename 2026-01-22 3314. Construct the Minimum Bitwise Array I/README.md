# 🔢 3314. Minimum Bitwise Array

This problem asks you to reverse-engineer a bitwise OR operation.

For each element `nums[i]`, find the **smallest integer `j`** such that:

j | (j + 1) == nums[i]

If no such integer exists, return `-1` for that position.
- **Leetcode Link:** [LeetCode 3314 – Minimum Bitwise Array](https://leetcode.com/problems/minimum-bitwise-array-i/)


---

## 🧠 Core Observation

The expression:

j | (j + 1)

has predictable behavior:

- `(j + 1)` flips the **rightmost 0-bit** in `j`
- Bitwise OR preserves all `1` bits
- The result is always **greater than `j`**

This means:
- `j` must be **strictly smaller than nums[i]**
- Checking values ≥ `nums[i]` is useless
- Searching from `nums[i] / 2` is a practical lower bound

---

## 🛠️ Algorithm

For each element in the array:

1. Initialize result as `-1`
2. Iterate `j` from `nums[i] / 2` to `nums[i] - 1`
3. Check if `(j | (j + 1)) == nums[i]`
4. Store the first valid `j` and stop searching

---

## ⏱️ Complexity Analysis

- **Time Complexity**:  
  O(n × nums[i]) in the worst case

- **Space Complexity**:  
  O(n) for the result array

---

## ⚠️ Common Mistakes

- Starting the search from `0` instead of `nums[i] / 2`
- Forgetting to break after finding the smallest valid `j`
- Assuming every number must have a valid answer
- Ignoring how adjacent integers behave under OR

---

## 🎯 Key Takeaway

This is not a math-heavy problem.  
It’s a **bit-pattern observation problem**.

Understand how `j` and `j + 1` interact at the binary level, and the solution becomes mechanical.
