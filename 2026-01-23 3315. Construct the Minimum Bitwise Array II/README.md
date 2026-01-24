# 🔢 Minimum Bitwise Array (Part 1 & Part 2)

- **Part 1:** [LeetCode 3314 – Minimum Bitwise Array](https://leetcode.com/problems/minimum-bitwise-array/)
- **Part 2:** [LeetCode 3315 – Minimum Bitwise Array II](https://leetcode.com/problems/minimum-bitwise-array-ii/)

---

## 🧠 Problem Summary

For each number `x` in `nums`, find the **minimum integer `j`** such that:

j | (j + 1) == x

If no such `j` exists, return `-1`.

Part 2 is the same logical problem as Part 1, except:
- Results may exceed 32-bit range
- You must use **64-bit arithmetic**

---

## 🔍 Bitwise Observation (Core Logic)

When incrementing an integer:
- `(j + 1)` flips the **lowest zero bit** of `j`
- All lower bits become `0`
- OR-ing with `j` preserves all `1` bits

So for a valid `x`:
- Find the **first zero bit**
- Flip the bit immediately below it
- That produces the **smallest possible `j`**

---

## 🛠️ Algorithm

For each `x`:

1. If `x == 2`, return `-1`  
   (Binary `10` cannot be produced by `j | (j+1)`)

2. Iterate bits from low to high
3. Find the first bit where `x[i] == 0`
4. Flip bit `(i-1)` using XOR
5. Store the result

---

## ⚠️ Why `x == 2` Fails

Binary `10`:
- No integer `j` exists where OR-ing with `j+1` results in `10`
- Every valid OR result must have the lowest bit set

This is not a guess. It’s a structural impossibility.

---

## ⏱️ Complexity

- **Time:** O(n × log(maxValue)) → effectively O(n)
- **Space:** O(n)

---

## 🧩 Part 1 vs Part 2

| Aspect | Part 1 | Part 2 |
|------|--------|--------|
| Output type | `int` | `long long` |
| Bit range | 32-bit | 64-bit |
| Logic | Same | Same |
| Trickiness | Medium | Medium (overflow traps) |

---

## 🎯 Final Takeaway

This problem punishes brute force and rewards understanding how **binary carries work**.

If you solved this by looping `j` values, you missed the point.
If you solved it with bit inspection, you’re thinking correctly.
