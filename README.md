# knights-tour
solutions for the knight's tour problem

## brute force

run:
```bash
g++ brute.cpp chessboard.cpp -o brute-force
./brute-force <initialLine> <initialColumn>
```

strategy result example:
```
./brute-force 0 0
Path:
        1       60      39      34      31      18      9       64
        38      35      32      61      10      63      30      17
        59      2       37      40      33      28      19      8
        36      49      42      27      62      11      16      29
        43      58      3       50      41      24      7       20
        48      51      46      55      26      21      12      15
        57      44      53      4       23      14      25      6
        52      47      56      45      54      5       22      13


Execution time: 4.71557 seconds
Steps: 8250733
```

## backtracking

run:
```bash
g++ backtracking.cpp chessboard.cpp -o back-tracking
./back-tracking <initialLine> <initialColumn>
```

strategy result example:
```
./back-tracking 0 0
Path:
        1       26      3       48      45      28      13      64
        4       49      46      27      14      63      44      29
        25      2       59      56      47      42      15      12
        58      5       50      53      62      55      30      43
        39      24      57      60      41      52      11      16
        6       21      40      51      54      61      34      31
        23      38      19      8       33      36      17      10
        20      7       22      37      18      9       32      35


Execution time: 0.00154346 seconds
Steps: 1643
```