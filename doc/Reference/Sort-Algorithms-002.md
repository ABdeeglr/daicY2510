# Analysis on Sort Algorithms

## Section I: Analysis on Selection Sort(SS) and Insertion Sort(IS)

|     |  SS | IS  |
| --- | --- | --- |
| Less Times | $\frac{N^2}{2}$ | Badest: $\frac{N^2}{2}$, Average: $\frac{N^2}{4}$, Best: $N-1$ |
| Exch Times | $N - 1$ | Badest:  $\frac{N^2}{2}$, Average: $\frac{N^2}{4}$, Best: $0$ |

Accerlating Possibility:
1. IS can be accerlated on `less` stage, because binary search can find the position quickly, by which from $\frac{N^2}{4}$ --> $\log_2^N + \log_2^(N-1)+\cdots$ .
2. If using linked list, `exch` always costs O(1).
3. Every `exch` access the array twice, and if not use `exch` but move every element by one by one in every cycle, we can decrease the half times of accessing the array.
