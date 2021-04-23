# Algorithm in graphs

## Currency Exchange

|||
| :---                 | :---              |
| Time limit           | 1.00 second       |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

Several currency exchange points are working in our city. Let us suppose that each point
specializes in two particular currencies and performs exchange operations only with these 
currencies. There can be several points specializing in the same pair of currencies. Each 
point has its own exchange rates, exchange rate of `A` to `B` is the quantity of `B` you
get for `1A`. Also, each exchange point has some commission, the sum you have to pay for
your exchange operation. Commission is always collected in source currency.

For example, if you want to exchange `100` **US Dollars** into **Russian Rubles** at the 
exchange point, where the exchange rate is `29.75`, and the commission is `0.39` you will 
get `(100 - 0.39) * 29.75 = 2963.3975RUR`.

You surely know that there are `N` different currencies you can deal with in our city. Let
us assign unique integer number from `1` to `N` to each currency. Then each exchange point
can be described with `6` numbers: integer `A` and `B` - numbers of currencies it exchanges,
and real **RAB**, **CAB**, **RBA** and **CBA** - exchange rates and commissions when 
exchanging `A` to `B` and `B` to `A` respectively.

Nick has some money in currency `S` and wonders if he can somehow, after some exchange 
operations, increase his capital. Of course, he wants to have his money in currency `S` in 
the end. Help him to answer this difficult question. Nick must always have non-negative 
sum of money while making his operations.

#### Input format

The first line contains four numbers: `N` - the number of currencies, `M` - the number of 
exchange points, `S` - the number of currency Nick has and `V` - the quantity of currency
units he has. The following `M` lines contain `6` numbers each - the description of the
corresponding exchange point - in specified above order. Numbers are separated by one or
more spaces. `1 ≤ S ≤ N ≤ 100`, `1 ≤ M ≤ 100`, `V` is real number, `0 ≤ V ≤ 1000`.

For each point exchange rates and commissions are real, given with at most two digits after
the decimal point, `1e-2 ≤ rate ≤ 1e2`, `0 ≤ commission ≤ 1e2`.

Let us call some sequence of the exchange operations simple if no exchange point is used
more than once in this sequence. You may assume that ratio of the numeric values of the 
sums at the end and at the beginning of any simple sequence of the exchange operations
will be less than `10000`.

#### Output format

If Nick can increase his wealth, output **YES**, in other case output **NO**.

#### Example 1

``` cpp
IN                                          OUT

3 2 1 10.0                                  NO
1 2 1.0 1.0 1.0 1.0
2 3 1.1 1.0 1.1 1.0
```

#### Example 2

``` cpp
IN                                          OUT

3 2 1 20.0                                  YES
1 2 1.0 1.0 1.0 1.0
2 3 1.1 1.0 1.1 1.0
```

## Mobile Telegraphs

|||
| :---                 | :---              |
| Time limit           | 3.00 seconds      |
| Memory limit         | 64Mb              |
| Input                | standard input    |
| Output               | standard output   |

Each fighter of the `25`th Rifle Division has been given the newest communication device —
a mobile telegraph. It can be used for sending telegrams to the command and to fellow 
fighters right at the battlefield. Unfortunately, the design of telegraphs is still far
from being perfect, so messages can be sent only between some pairs of telegraphs.

Each device has a unique number, which is a string consisting of ten decimal digits. A 
message can be sent from a telegraph `a` to a telegraph `b` only if the number `b` can
be obtained from the number `a` by **changing** exactly one digit or by **swapping** two
digits, and the time of sending a message from the telegraph `a` to the telegraph `b`
depends on the length of the longest common prefix of their numbers: the longer the 
common prefix is, the faster the message is sent.

During a battle, Anka noticed from her well-camouflaged position the group of Whites
trying to bypass Red Army fighters in the rear. What minimal time is required to deliver
this information from Anka to Chapaev by telegraph, using, possibly, telegraphs of other
Red Army fighters?

#### Input format

The first line contains the number `n` of fighters in the division (`2 ≤ n ≤ 50000`).
The second line contains ten integers in the range from `1` to `10000` separated with a 
space written in the nonascending order. These are the times of sending a message from 
one telegraph to another if the length of their common prefix is zero, one, two, …, nine.
The next `n` lines contain the numbers of telegraphs given to the fighters of the 
division. The number of Anka's telegraph is described first, and the number of Chapaev's
telegraph is described last. All the numbers of telegraphs are different.

#### Output format

Output the only line `-1` if it is impossible to deliver the message to Chapaev. Otherwise,
in the first line output the minimal time required to deliver the message. In the second 
line output the number of fighters in the delivery path, and in the third line output 
their numbers separated with a space in the order from Anka to Chapaev. The fighters of 
the `25`th Division are numbered from `1` to `n` in the order in which their mobile
telegraphs are described in the input. If there are several ways to deliver the message
in minimal time, output any of them.

#### Example 1

``` cpp
IN                                          OUT

5                                           211
100 10 10 10 1 1 1 1 1 1                    5
9123493342                                  1 2 4 3 5
3123493942
9223433942
3223493942
9223433945
```

#### Example 2

``` cpp
IN                                          OUT

2
1 1 1 1 1 1 1 1 1 1                         -1
0123493342
0223433945
```
