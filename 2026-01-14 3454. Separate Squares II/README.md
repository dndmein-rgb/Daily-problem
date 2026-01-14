# 3454. Separate Squares II

## 📋 Problem Description
**Difficulty**: Hard  
**Pattern**: Sweep Line + Segment Tree (Area of Union of Rectangles)

Unlike Separate Squares I, where squares could be treated independently, this version requires calculating the **union area** of overlapping squares. 

---

## 💡 The "Complex Work": Sweep Line & Segment Tree

When squares overlap, simply summing $L^2$ results in double-counting. We must use the **Sweep Line Algorithm** combined with a **Segment Tree** to find the area of the union.

### 1. Sweep Line Strategy
Imagine a horizontal line sweeping from the lowest $y$ to the highest $y$.
- At each `y` coordinate where a square starts or ends, the "active" width on the $x$-axis changes.
- The area between two $y$ events is: $\text{Width of Union on X} \times (y_{next} - y_{curr})$.



### 2. Segment Tree for Union Length
The segment tree manages the $x$-intervals. Each node in the tree tracks:
- `count`: How many active squares cover this interval.
- `length`: The total length of this interval that is covered by **at least one** square.



### 3. Coordinate Compression
Since $x$ coordinates can be very large, we "compress" them by only storing the unique $x$ and $x+l$ values that actually appear in the input. This transforms the infinite $x$-axis into at most $2N$ discrete segments.

---

## 📊 Complexity Analysis

| Component | Time Complexity | Reason |
| :--- | :--- | :--- |
| **Coordinate Compression** | $O(N \log N)$ | Sorting $2N$ x-coordinates and removing duplicates. |
| **Event Sorting** | $O(N \log N)$ | Sorting $2N$ y-events (start and end of squares). |
| **Segment Tree Updates** | $O(N \log N)$ | Performing $2N$ updates, each taking $O(\log N)$ time. |
| **Binary Search (Pass 2)** | $O(N \log N)$ | Re-sweeping or searching through $2N$ intervals. |
| **Total Time** | **$O(N \log N)$** | The complexity is dominated by sorting and tree operations. |

| Resource | Space Complexity | Reason |
| :--- | :--- | :--- |
| **Event Storage** | $O(N)$ | Storing $2N$ event objects. |
| **Segment Tree** | $O(N)$ | The tree requires $4 \times (2N)$ nodes for the compressed coordinates. |
| **Coordinate Map** | $O(N)$ | Storing the unique sorted x-coordinates. |
| **Total Space** | **$O(N)$** | All auxiliary structures scale linearly with the number of squares. |

---

## 📊 Visual Trace
Suppose we have overlapping squares:
```text
  y ^
    |    [Square B]
    |  +-------+
    |  |  +----+--+
    |  +--|----+  | [Square A]
    |     +-------+
____+_________________> x
