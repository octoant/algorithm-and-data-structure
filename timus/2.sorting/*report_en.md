# Sorting

## Spy

|||
| :---                 | :---              |
| Time limit           | 0.25 second       |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

The secret service detected an acting foreign agent. Frankly speaking — a spy. A surveillance
showed that each week the spy sends strange unreadable texts to somebody via the Internet.
In order to find out which information became available to the spy, it is necessary to decipher
the texts. Secret service agents got into the spy's apartment, discovered a cipher machine,
and found out the principle of its operation.

An input of the machine is a text line S<sub>1</sub> = s<sub>1</sub>s<sub>2</sub>...s<sub>N</sub>.
The machine constructs all cyclic permutations of this line, i.e., S<sub>2</sub> = s<sub>2</sub>
s<sub>3</sub>...s<sub>N</sub>s<sub>1</sub>, ..., S<sub>N</sub> = s<sub>N</sub>s<sub>1</sub>
s<sub>2</sub>...s<sub>N-1</sub>. Then the set S<sub>1</sub>, S<sub>2</sub>, ..., S<sub>N</sub> 
is sorted lexicographically in the ascending order, and the lines are written out in this order
in a column, one under another. Thus an array `N × N` is obtained. One of the rows of this array
contains the initial word. The number of this row and the last column of the array are the output
of the machine.

For example, if the initial word S<sub>1</sub> = abracadabra, then the following array is formed:

-   aabracadabr = S<sub>11</sub>
-   abraabracad = S<sub>8</sub>
-   abracadabra = S<sub>1</sub>
-   acadabraabr = S<sub>4</sub>
-   adabraabrac = S<sub>6</sub>
-   braabracada = S<sub>9</sub>
-   bracadabraa = S<sub>2</sub>
-   cadabraabra = S<sub>5</sub>
-   dabraabraca = S<sub>7</sub>
-   raabracadab = S<sub>10</sub>
-   racadabraab = S<sub>3</sub>

In this case, the output of the machine is the number `3` and the line rdarcaaaabb.

So it is clear how the cipher machine operates. However, no deciphering machine was found.
But as the information can certainly be deciphered (otherwise there is no sense in sending it),
you have to invent a deciphering algorithm.

#### Input format

The first and the second lines contain an integer and a string respectively. This is the
output of the cipher machine. Both the number and the length of the string do not exceed
`100000`. The string may contain only the letters `a-z`, `A-Z` and the underlining
character. The lexicographic order on the set of words is determined by the following 
order of characters:

``` cpp
ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz
```

The characters here are given in the ascending order.

#### Output format

The only line should contain the initial message.

#### Example

``` cpp
IN                                          OUT

3                                           abracadabra
rdarcaaaabb
```

## Country of Fools

|||
| :---                 | :---              |
| Time limit           | 1.0 second        |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

The chief traffic policeman of the Country of Fools wants to impose a speed limit on the
motorway going from the Field of Wonders to the City of Simple Simons. He ordered `n` speed
limit signs. When the order arrived it turned out that the signs had different numbers on
them, which showed limits in kilometers per hour. There were `k` different limits: `n_1`
signs with the first limit, `n_2` signs with the second limit, etc.; `n_1 + … + n_k = n`.

To make the life of drivers not so easy, the chief policeman decided to place the signs on
the motorway in such a way that a driver would have to change speed as many times as possible.
According to the traffic regulations in the Country of Fools, a speed limitation is valid
until the following speed limit sign, and the speed shown in the sign must be observed exactly.
For example, if there is the number `60` on the sign, then a car must go until the following
sign with the speed of exactly `60` kilometers per hour.

#### Input format

The first line contains the number `k` of different types of speed limit signs; `1 ≤ k ≤ 10000`.
The second line contains positive integers `n_1`, …, `n_k` separated with a space. The sum
of all ni does not exceed `10000`.

#### Output format

Output the order in which the signs must be place on the motorway, in the form of `n` integers
in the range from `1` to `k`. Assume that a driver must change speed when the car passes 
by the first sign, irrespective of the initial speed. If there are several solutions, you
may output any of them.

#### Example

``` cpp
IN                                          OUT

2                                           1 2 1 2
2 2
```
