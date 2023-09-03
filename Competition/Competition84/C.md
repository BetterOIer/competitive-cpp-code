当$p \le x$的时候，令$a = p, b = p(p-1),c = \dfrac{n-(p-1)p^2}{p^2}$

当$p-1=x$的时候，令$a=6,b=p-3,c=p^2-4p+6$,注意这里可能出现$b,c$为负数，所以要对$p \le 5$也就是$n \le 20$爆搜

当$p-1>x$的时候,$n = ab+bc+ac \Longleftrightarrow n+a^2 = (a+b)(a+c)$<br>
故我们需要找到某个正整数$a$，使得$n+a^2$可以分解为两个大于$a$的正整数之积即可<br>
$n+a^2 \bmod (x+1) = n+p^2 \bmod(x+1) = (x+1)p^2 mod (x+1) = 0$<br>
考虑$a = p mod (x+1),b = x+1 - a,c = \dfrac{n+a^2}{x+1}-a$ 