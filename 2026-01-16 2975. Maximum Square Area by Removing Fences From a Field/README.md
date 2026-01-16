# 2975. Maximize Square Area by Removing Fences



## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Geometry + Hashing  

There is a rectangular field of size `(m - 1) x (n - 1)` with corners at `(1, 1)` and `(m, n)` containing some horizontal and vertical fences given in arrays `hFences` and `vFences` respectively.

- Horizontal fences are from `(hFences[i], 1)` to `(hFences[i], n)`  
- Vertical fences are from `(1, vFences[i])` to `(m, vFences[i])`  

Return the **maximum area of a square field** that can be formed by removing some fences (possibly none), or `-1` if it is impossible to make a square field.  

The result should be returned modulo `1e9 + 7`.

---

## 🛑 Constraints
- `1 <= m, n <= 10^9`
- `1 <= hFences.length, vFences.length <= 10^5`
- Fence positions are **1-indexed**
- No duplicate fences

---

## 📌 Examples

### Example 1

**Input**
```
m = 4, n = 3
hFences = [2]
vFences = [2]
```

**Output**
```
4
```

**Explanation**
Possible horizontal gaps = {1, 2}  
Possible vertical gaps = {1, 2}  
Largest common gap = 2 → area = 4

---

### Example 2

**Input**
```
m = 6, n = 7
hFences = [2, 4]
vFences = [3]
```

**Output**
```
9
```

**Explanation**
Largest square side possible is 3 → area = 9

---

## 🧠 Key Insight
A square exists **only if**:
- a horizontal gap length == a vertical gap length

So the problem reduces to:
1. Generate **all horizontal gaps**
2. Generate **all vertical gaps**
3. Find the **largest common gap**

---

## 💡 Approach

1. Add boundary fences (`1` and `m / n`)
2. Sort fence positions
3. Compute all pairwise differences for horizontal fences
4. Store them in a hash set
5. Iterate vertical differences and check if they exist in the set
6. Track the maximum valid square side
7. Return `side² % MOD`

---

## ⚙️ Complexity Analysis

| Metric | Complexity | Explanation |
|------|-----------|-------------|
| Time | `O(H² + V²)` | All fence pairs |
| Space | `O(H²)` | Hash set for gaps |

---

## ✅ Takeaways
- Square = same gap in both directions
- Boundaries matter, always include them
- Hashing turns brute force into a passable solution
- Geometry problems love pretending to be math-heavy while actually being set problems
