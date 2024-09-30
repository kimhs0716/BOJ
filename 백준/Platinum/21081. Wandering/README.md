# [Platinum IV] Wandering - 21081 

[문제 링크](https://www.acmicpc.net/problem/21081) 

### 성능 요약

메모리: 34624 KB, 시간: 44 ms

### 분류

미적분학, 수학, 확률론

### 제출 일자

2024년 9월 28일 12:52:51

### 문제 설명

<p>Rikka is a talented student.</p>

<p>She likes to wander in the corridor while solving ICPC problems. Specifically, she will do a random walk for $n$ steps. In the $i$-th random step, she will choose one of the vectors $(x, y)$ such that $x, y \in \mathbb{R}$ and $x^2 + y^2 \le R_i^2$ with equal probability. And then she will walk along the vector. In other words, if she stood at $(A, B)$ before the random step, she will stand at $(A + x, B + y)$ afterwards. Before wandering, she stands at the door $(0, 0)$.</p>

<p>After wandering, she was curious about the expectation of the square of Euclidean distance to point $(0, 0)$. In other words, she wants to know the expected value of $x^2 + y^2$, if she stands at $(x, y)$ after all $n$ random steps.</p>

### 입력 

 <p>The first line contains an integer $n$, the number of random steps.</p>

<p>The second line contains $n$ positive integers $R_i$, the parameter of the $i$-th random step.</p>

<p>It is guaranteed that $1 \le n \le 50\,000$ and $1 \le R_i \le 1000$.</p>

### 출력 

 <p>You need to output $d$, the expected value of $x^2 + y^2$. Assuming the correct result is $d^*$, you need to ensure that $\frac{|d - d^*|}{\max\{d^*, 1\}} \leq 10^{-6}$.</p>

