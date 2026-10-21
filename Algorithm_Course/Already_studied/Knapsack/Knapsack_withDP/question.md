# 0/1 Knapsack

Write a C++ program to find the maximum total profit that can fit in a
knapsack with capacity `W`.

You are given `n` items. Each item has a weight and a profit. Every item can
be selected at most once: take the complete item or skip it. Fractions are
not allowed, and the total weight of selected items must not exceed `W`.

Print the maximum possible profit.

## Example

```text
Number of items: 4
Capacity: 7

Item 0: weight = 1, profit = 1
Item 1: weight = 3, profit = 4
Item 2: weight = 4, profit = 5
Item 3: weight = 5, profit = 7
```

Expected output:

```text
Maximum profit = 9
Selected items: 1 and 2
```

Items 1 and 2 have total weight `3 + 4 = 7` and total profit `4 + 5 = 9`.
