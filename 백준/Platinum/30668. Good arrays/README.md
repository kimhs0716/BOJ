# [Platinum III] Good arrays - 30668 

[문제 링크](https://www.acmicpc.net/problem/30668) 

### 성능 요약

메모리: 437992 KB, 시간: 1584 ms

### 분류

수학, 다이나믹 프로그래밍, 정수론, 조합론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Recently Vasya learned about integer division. Inspired by this sacred knowledge, he decided to learn more about arrays of positive integers which satisfy some divisibility conditions. More precisely, Vasya calls an array $a=\{a_1,a_2,\ldots,a_n\}$ <em>good</em> iff for every $i$ from $1$ to $n-1$, $a_i$ is divisible by $a_{i+1}$. Please help him count the number of good arrays of length $n$ consisting of integer numbers not greater than $c$.</p>

### 입력 

 <p>The only input line contains two integers $n$ and $c$ ($1 \le n, c \le 5 \cdot 10^7$) --- the length of the array and the maximum allowed value.</p>

### 출력 

 <p>Output a single integer --- the total number of good arrays of length $n$ consisting of positive integers not greater than $c$. As this number might be quite large, please output its remainder modulo $998\,244\,353$.</p>

