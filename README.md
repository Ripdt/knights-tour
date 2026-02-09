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
./brute-force 2 2
Path:
        39      60      35      52      37      50      43      8
        34      53      38      61      42      9       46      49
        59      40      1       36      51      48      7       44
        54      33      58      41      62      45      10      47
        57      20      55      2       29      4       63      6
        32      17      22      15      24      13      26      11
        21      56      19      30      3       28      5       64
        18      31      16      23      14      25      12      27


Execution time: 276.347 seconds
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