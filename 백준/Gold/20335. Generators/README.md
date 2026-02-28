# [Gold I] Generators - 20335 

[문제 링크](https://www.acmicpc.net/problem/20335) 

### 성능 요약

메모리: 11372 KB, 시간: 60 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2026년 2월 28일 19:48:14

### 문제 설명

<p>The volcanic island of Fleeland has never had a proper electric net, but finally the administration of the island have agreed to build the island's power plants and network.</p>

<p>On the island's coast are its $n$ cities. The administration has surveyed the cities and proposed $m$ of them as possible locations for a power plant, with the $i$th proposal stating that the company can build a plant in city $c_i$ for cost $a_i$.</p>

<p>These power plants are very modern and a single plant could power the whole island, but the volcano makes building power lines across the island a dangerous affair. For $1 \leq i < n$, the company can build power lines between cities $i$ and $i+1$ for a cost of $b_i$, and between cities $n$ and $1$ for a cost of $b_n$. A city will receive power if it contains a power plant or is connected to a city with a power plant via power lines.</p>

<p>What is the cheapest way to power all the cities on the island?</p>

### 입력 

 <ul>
	<li>One line containing two integers $n$ ($3\leq n \leq 10^5$) and $m$ ($1\leq m \leq n$), the number of cities and the number of possible locations for a power plant.</li>
	<li>Then follow $m$ lines, the $i$th of which contains $c_i$ ($1 \leq c_i \leq n$) and $a_i$ ($1 \leq a_i \leq 10^9$), the $i$th possible location for a power plant, and the cost to build it.</li>
	<li>Then follows a line containing $n$ integers $b_i$ ($1 \leq b_i \leq 10^9$), the costs of building the power lines.</li>
</ul>

<p>The values of $c_{1,\ldots,n}$ are unique and given in strictly increasing order.</p>

### 출력 

 <p>Output the minimal cost of powering all cities on the island.</p>

