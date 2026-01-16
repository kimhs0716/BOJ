# [Platinum V] Escalators - 16338 

[문제 링크](https://www.acmicpc.net/problem/16338) 

### 성능 요약

메모리: 17372 KB, 시간: 316 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 트리, 트리에서의 다이나믹 프로그래밍

### 제출 일자

2026년 1월 16일 22:25:15

### 문제 설명

<p>Binary Casino is a very special skyscraper building consisting of N floors connected by a tricky network of high speed escalators.</p>

<p>The floor connections are designed in a way that if there is an escalator going from floor A to floor B, then there is another escalator going from floor B to floor A as well. Also, for any two floors A and B, there is exactly one way to go from floor A to floor B.</p>

<p>Your manager decided to organize a promotion game to attract more customers. The game has the following rules:</p>

<ul>
	<li>The game is played in one or more rounds.</li>
	<li>In each round a customer can choose a floor S on which that round starts. At this moment he earns some fixed number of tokens t(S) associated with floor S. Then he may move to other floors using escalators.</li>
	<li>If a customer decides to take an escalator from floor A to floor B and has X tokens he has to pay X − (X AND t(B)) tokens to enter floor B, where “AND” is a bitwise AND operator, “−” is a standard minus operator on numbers, and t(B) is a number of tokens associated with floor B.</li>
	<li>A customer can decide to stop the round on any floor (including S) and keep the tokens from that round. Then he can start a new round from any floor if it is possible.</li>
	<li>No two rounds may have the same pair of starting and ending floors, not even in the opposite direction, i.e. when considering exchanged starting and ending floors.</li>
</ul>

<p>Your manager is curious about the maximum number of tokens a customer can earn in the game.</p>

### 입력 

 <p>The first line of input contains an integer N (1 ≤ N ≤ 3 · 10<sup>5</sup>) describing the number of floors in the casino skyscraper. The second line contains N integers V<sub>i</sub> (0 ≤ V<sub>i</sub> < 2<sup>20</sup>). The i-th integer V<sub>i</sub> describes the number of tokens that a customer earns on the i-th floor. After that, N −1 lines follow. Each line contains two integers A and B (0 ≤ A, B < N) which describe an escalator connection between floors A and B.</p>

### 출력 

 <p>Output a single number – the maximum number of tokens a customer can earn.</p>

