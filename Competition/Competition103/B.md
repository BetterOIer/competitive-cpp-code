## 题目描述
给定一个$n$个点$m$条边的有向图。不保证不存在重边自环。

记$f(x,y,k)$表示从$x$到$y$经过恰好$k$条边的不同路径数量，两条路径不同当且仅当存在存在某个$i$使得两条路径的第$i$条边不同。

称一个有向图是有趣的，当且仅当存在$x,y$，不存在任何正整数$M$，使得$k \ge M$时$f(x,y,k)$为一常数，也即$\lim\limits_{k\to+\infty}f(x,y,k)$不存在。

你需要判断给定的有向图是不是有趣的。

本题捆绑测试。

## 输入描述
第一行用空格分开的两个整数$n$和$m$。

接下来$m$行，每行两个整数$u$和$v$表示图中有$u \to v$这条边。

## 输出描述
一行，`Yes`
或者`No`
表示是否是有趣的。

## 样例

```input1
3 3
1 2
2 3
3 1
```

```output1
Yes
```

样例 1 解释

考虑$f(1,1,t)$，当$t \bmod 3=0$时$f(1,1,t)>0$，当$t \bmod 3 \ne 0$时$f(1,1,t)=0$，故不存在一个整数$M$，使得$t \ge M$时$f(1,1,t)$为常数，故该图是有趣的。

```input2
3 3
1 1
1 2
2 3
```

```output2
No
```

```input3
3 4
1 2
2 1
2 3
3 2
```
```output3
Yes
```

其他样例
见下发文件

## 数据范围
对于$10\%$的数据，$1 \le n,m \le 20$。

对于另外$20\%$的数据，$1 \le n,m \le 300$。

对于另外$20\%$的数据，$1 \le n,m \le 2000$。

对于另外$10\%$的数据，保证图中无自环。

对于$100\%$的数据，$1 \le n,m \le 5 \times 10^5$。