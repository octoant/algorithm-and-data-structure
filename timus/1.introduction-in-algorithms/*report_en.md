# Introduction in algorithms

## Stone Pile

|||
| :---                 | :---              |
| Time limit           | 1.0 second        |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

You have a number of stones with known weights `w_1`, ..., `w_n`. Write a program that
will rearrange the stones into two piles such that weight difference between the piles
is minimal.

#### Input format

Input contains the number of stones `n` (`1 ≤ n ≤ 20`) and weights of the stones
`w_1`, ..., `w_n` (integers, `1 ≤ w_i ≤ 100000`) delimited by white spaces.

#### Output format

Your program should output a number representing the minimal possible weight difference
between stone piles.

#### Example

``` cpp
IN                                          OUT

5                                           3
5 8 13 27 14
```

## Hyperjump

|||
| :---                 | :---              |
| Time limit           | 1.0 second        |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

Developed in the beginning of `XXI` century, hyperjump remains the primary method of
transportation for distances up to thousands parsecs. But physicists have recently 
discovered an amazing phenomenon. They believe the duration of the hyperjump alpha
phase can be easily controlled. Alpha phase is the period when hyper-spacecraft
accumulates its gravity potential. The larger is the gravity potential accumulated,
the less energy is required to complete the hyperjump. Your task is to write a program,
which would help pilots decide when to enter and when to leave the alpha-phase,
in order for the hyperspacecraft to accumulate the largest possible gravity potential.

The most crude gravity field model (which you will have to use) yields the sequence
of integers `p_i`, which represent field intensities at different moments in time.
According to this model, if the alpha-phase begins at moment `i` and ends at moment `j`,
then the value of gravity potential accumulated will be equal to the sum of sequence
elements at places from `i`-th to `j`-th inclusive.

#### Input format

The first line of the input contains an integer `N` being the number of elements in
the intensity values sequence (`0 ≤ N ≤ 60000`). Next `N` lines specify sequence 
elements, each line containing a single integer `p_i` (`−30000 ≤ p_i ≤ 30000`).

#### Output format

The only line of output contains the largest possible value of the gravity potential
that can be accumulated by a hyperspacecraft during the alpha phase. You should assume
that the initial gravity potential of a hyperspacecraft is equal to zero.

#### Example 1

``` cpp
IN                                          OUT

10                                          187
31
-41
59
26
-53
58
97
-93
-23
84
```

#### Example 2

``` cpp
IN                                          OUT
3                                           0
-1
-5
-6
```
