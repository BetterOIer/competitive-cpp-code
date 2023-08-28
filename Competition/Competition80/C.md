## 题目描述

黑板上写着$n$ 个非负整数，其中第$i (1 \le i \le n)$个整数为 $a_i$。  
你想要在黑板上玩一个游戏。每次你可以选择两个当前写在黑板上的非负整数$x$与$y$，将他们擦掉，并在黑板上额外写上$x$异或$y$。  
但是，仅仅只通过这一种操作来玩游戏，未免太过单调了一些。因此，你有一次进行加一操作的机会。具体地，在任意时刻，你可以选择当前写在黑板上的任意一个整数$x$，将他擦掉，并将$x + 1$写在黑板上。你必须进行**恰好一次**这种操作。  
你希望不断进行上述操作，直到黑板上最终只剩下一个整数。你希望最大化这个剩余的整数。现在你想要知道，如果你采取最优的策略，那么最终剩下的整数会是多少。

## 输入格式

第一行一个正整数$n$。  
接下来一行输入$n$个数，输入$a_i$。

## 输出格式

输出一行，每行一个数表示剩下的数字最大是多少。

## 样例数据
```input1
4
1 2 1 2
```
```output1
7
```
```input2
5
1 2 3 4 5
```
```outpu12
14
```

样例 3 / 4见下发文件。

## 数据范围
对于$100\%$的数据，$1 \le n \le 10^6$，$0 \le ai<2^{60}$。

子任务 1（15 分）：$n \le 20 $
子任务 2（5 分）：$a_i<21$
子任务 3（10 分）：$a_i<22$
子任务 4（20 分）：$a_i<216<2^{16}$
子任务 5（20 分）：$n \le 10^5，a_i<2^{32}$
子任务 6（15 分）：$n \le 2 \times 10^5$
子任务 7（15 分）：没有额外的限制。


时间限制：1000 ms  
空间限制：1024 MiB  
题目类型：传统型  
答案检查器：文本比较