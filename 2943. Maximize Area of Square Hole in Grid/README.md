# 2943. Maximize Area of Square Hole in Grid

## 📋 Problem Description
**Difficulty**: Medium  
**Pattern**: Sorting + Consecutive Streaks  

You are given a grid of size `n x m`.

Some horizontal bars (`hBars`) and vertical bars (`vBars`) are removed.  
Removing **k consecutive bars** creates a hole of size `k + 1`.

Your task is to return the **maximum possible area of a square hole**.

---

## 🛑 Constraints
- `1 <= n, m <= 10^9`
- `1 <= hBars.length, vBars.length <= 10^5`
- Bar indices are **1-based**
- No duplicate bars

---

## 📌 Examples

### Example 1

**Input**
```
n = 2, m = 2
hBars = [1]
vBars = [1]
```

**Output**
```
4
```

**Explanation**  
One horizontal + one vertical bar removed → square of side `2`.

---

### Example 2

**Input**
```
n = 3, m = 3
hBars = [1,2]
vBars = [2]
```

**Output**
```
4
```

**Explanation**  
- Longest horizontal streak = 2 → side = 3  
- Vertical streak = 1 → side = 2  
- Square side = min(3, 2) = 2  
- Area = 4

---

## 🧠 Key Insight
A square hole requires:
- consecutive **horizontal bars**
- consecutive **vertical bars**

The square’s side length is:
```
1 + min(longest horizontal streak, longest vertical streak)
```

---

## 💡 Approach

1. Sort `hBars` and `vBars`
2. Find longest consecutive sequence in each
3. Take the minimum of the two
4. Add `1` to get square side
5. Return `side²`

---

## ⚙️ Complexity Analysis

| Metric | Complexity | Explanation |
|------|-----------|-------------|
| Time | `O(H log H + V log V)` | Sorting bars |
| Space | `O(1)` | No extra data structures |

---

## ✅ Takeaways
- Grid size is irrelevant after bar removal
- Consecutive bars matter, not count
- Square is limited by the weaker direction
- Clean example of reducing geometry to array streaks
