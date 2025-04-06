# CodeClash-Dynamic-Programmers


## Approach of A

Converted all dates to a single day index (ignoring leap years).
Marked absent days as 0 and all other days as 1 in a presence array.
Used a prefix sum array to quickly compute the number of present days in any range.
Starting from the latest known absence date, started simulating forward day by day and check for each year if at least d days were present. The first valid date is printed as the anser.

---

## Approach of B
Used DSU to join all adjacent 0 cells to connectred component. For every 0 cell grid its parent and size of component in find out using DSU and printed the number distinct components and size of each componenet.

---

## Approach of C
Read bar widths and classify each as either black (0) or white (1) based on closeness to reference widths using a 5% tolerance margin.
Converted the bar sequence into a binary string of 0s and 1s, then determine orientation using start/stop sentinel codes. Reversed the string if needed.
Divided the bitstring into 6-bit groups and decode each group using a lookup table. Extracted the data string while validating formatting.
Computed the checksum values C and K from the decoded string using weighted sums and validate against the final two characters. Printed the result if valid, or an error message otherwise.

---


