# CodeClash-Dynamic-Programmers

# Problem A

## Approach

1. Convert all dates to a single day index (ignoring leap years).
2. Mark absent days as 0 and all other days as 1 in a presence array.
3. Use a prefix sum array to quickly compute the number of present days in any range.
4. Starting from the latest known absence date, simulate forward day by day and check for each year if at least `d` days were present. The first valid date is printed.

---
