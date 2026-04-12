# [Platinum II] 세진아, 향기가 세진 꽃밭에서, 지는 꽃잎을 세진 않으려 해 - 35161 

[문제 링크](https://www.acmicpc.net/problem/35161) 

### 성능 요약

메모리: 124056 KB, 시간: 220 ms

### 분류

수학, 조합론, 많은 조건 분기

### 제출 일자

2026년 4월 13일 08:50:13

### 문제 설명

<p>하지만 KCPC 운영을 위해서는 세진이는 운영진 현황을 안 세진 채로 둘 순 없다.</p>

<p>KCPC 2025의 운영진은 KAIST 소속의 동우, 컴퓨터학과(Computer Science) 소속 동현이, 물리학과(Physics) 세진이, 사이버국방학과(Cyber Defense) 지훈(가명)이 등 다양한 소속의 사람들로 구성되어 있다.</p>

<p>세진이는 KCPC 운영진의 자리를 배치하려고 한다. 대회 운영진들이 있을 방에는 $N\times M$개의 자리가 $N$행 $M$열의 모양으로 배치되어 있으며, 세진이는 각 자리에 <span style="color:#e74c3c;"><code>K</code></span>, <span style="color:#e74c3c;"><code>C</code></span>, <span style="color:#e74c3c;"><code>P</code></span> 중 하나를 배치할 것이다. 이때 임의의 연속된 두 행과 연속된 두 열로 이루어진 $2\times 2$ 자리에 대해, <span style="color:#e74c3c;"><code>K</code></span>, <span style="color:#e74c3c;"><code>C</code></span>, <span style="color:#e74c3c;"><code>P</code></span>가 각각 $1$개, $2$개, $1$개로 구성되어 있어야 한다.</p>

<p>$N$과 $M$이 주어졌을 때 세진이가 조건에 맞게 배치할 수 있는 경우의 수를 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 $T(1\leq T\leq 100\, 000)$가 주어진다.</p>

<p>두 번째 줄부터 $T$줄에 걸쳐 각 테스트 케이스 별로 한 줄씩 정수 $N,M(2\leq N,M\leq 100\, 000)$이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>첫 번째 줄부터 $T$줄에 걸쳐 각 테스트 케이스 별로 한 줄씩 정답을 $998\, 244\, 353$로 나눈 나머지를 출력한다.</p>

