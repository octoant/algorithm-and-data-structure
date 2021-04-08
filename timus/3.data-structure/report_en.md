# Data structure

## War Games 2

|||
| :---                 | :---              |
| Time limit           | 1.00 second       |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

#### Background

During the latest war games (this story is fully described in the problem ["War games"
](https://acm.timus.ru/problem.aspx?space=1&num=1458)) the Minister of Defense of the 
Soviet Federation comrade Ivanov had a good chance to make sure personally, that an 
alertness of the Soviet Army under his command is just brilliant. But there was a thing,
that continued to worry him. Being an outstanding commander, he realized, that only 
physical conditions of the soldiers were demonstrated. So the time came to organize 
one more war games and examine their mental capacity.

General Rascal was appointed to be responsible for the war games again. The general 
donated the allocated funds to the poor and went to bed free-hearted. In his dream,
the tactics manual appeared to him and described a scheme, that allows to organize 
the war games absolutely free of charge.

#### Problem

In accordance with this scheme, the war games are divided into `N` phases; and `N`
soldiers, successively numbered from `1` to `N`, are marching round a circle one after
another, i.e. the first follows the second, the second follows the third, ..., the 
`N-1`-th follows the `N`-th, and the `N`-th follows the first. At each phase, a single
soldier leaves the circle and goes to clean the WC, while the others continue to march.
At some phase, the circle is left by a soldier, who is marching `K` positions before the
one, who left the circle at the previous phase. A soldier, whose number is `K`, leaves 
the circle at the first phase.

Surely, Mr. Rascal cherished no hope about his soldiers' abilities to determine an 
order of leaving the circle. "These fools can not even paint the grass properly", - he 
sniffed scornfully and went to sergeant Filcher for an assistance.

#### Input format

The only line contains the integer numbers `N` (`1 ≤ N ≤ 100000`) and `K` (`1 ≤ K ≤ N`).

#### Output format

You should output the numbers of soldiers as they leave the circle. The numbers should
be separated by single spaces.

#### Example

``` cpp
IN                                          OUT

5 3                                         3 1 5 2 4
```

## White Streaks

|||
| :---                 | :---              |
| Time limit           | 1.00 second       |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

The life of every unlucky person has not only black but also white streaks. The Martian
Vas-Vas has a calendar in the form of an `m × n` table; he marks in this calendar days
when he had bad luck. If Vas-Vas had bad luck in the `j`-th day of the `i`-th week, he 
paints the cell (`i`, `j`) black. Initially, all cells are white.

Let rectangles of the form `1 × l` or `l × 1` be called segments of life. Maximal with
respect to inclusion white segments are called white streaks. Can you determine how many
white streaks there were in the life of Vas-Vas?

#### Input format

The first line contains integers `m`, `n`, and `k`, which are the size of the calendar
and the number of unlucky days in it (`1 ≤ m`, `n ≤ 30000`; `0 ≤ k ≤ 60000`). In the 
following `k` lines, unlucky days are given in the form of pairs (x<sub>i</sub>, 
y<sub>i</sub>), where x<sub>i</sub> is the number of the week to which the unlucky day
belongs and y<sub>i</sub> is the number of the day within this week (`1 ≤ xi ≤ m`;
`1 ≤ yi ≤ n`). Every unlucky day is given in the input only once.

#### Output format

Output the number of white streaks in the life of Vas-Vas

#### Example 1

``` cpp
IN                                          OUT

3 5 4                                       8
1 1
1 5
2 2
3 3
```

#### Example 2

``` cpp
IN                                          OUT

5 1 2                                       2
2 1
3 1
```
