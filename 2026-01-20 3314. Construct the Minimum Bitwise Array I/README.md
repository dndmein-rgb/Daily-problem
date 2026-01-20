# 🔢 Minimum Bitwise Array

This problem reverses a bitwise OR operation to recover the **smallest valid integer** that could have produced a given number.

---

## 🧠 Problem Summary

You are given an integer array `nums`.

For each `nums[i]`, find the **minimum integer `j`** such that:

j | (j + 1) == nums[i]


If no such integer exists, return `-1` for that index.

---

## 🔍 Key Observation

The operation:

j | (j + 1)


has predictable behavior:

- `(j + 1)` flips the **rightmost zero bit** in `j`
- The OR keeps all existing `1` bits
- Result is always **greater than `j`**

So:
- `j` must be **strictly less** than `nums[i]`
- Searching beyond `nums[i]` is pointless
- Starting from `nums[i] / 2` cuts useless iterations

---

## 🛠️ Algorithm

For each number in `nums`:

1. Initialize result as `-1`
2. Iterate `j` from `nums[i] / 2` to `nums[i] - 1`
3. Check if `(j | (j + 1)) == nums[i]`
4. Store the **first valid `j`** and stop

---

## ⏱️ Complexity

- **Time Complexity**:  
  Worst case `O(n × nums[i])`

- **Space Complexity**:  
  `O(n)` for the result array

---

## ⚠️ Common Pitfalls

- Starting `j` from `0` instead of `nums[i] / 2`
- Forgetting to break after finding the first valid `j`
- Assuming every number must have a solution
- Overthinking this as a pure bit-trick problem

---

## 🧠 Takeaway

This isn’t about clever hacks.  
It’s about recognizing how **adjacent integers behave under OR** and exploiting that pattern.

Once you see it, the solution becomes boring.  
That’s a good thing.
