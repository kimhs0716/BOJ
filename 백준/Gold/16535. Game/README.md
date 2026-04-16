# [Gold II] Game - 16535 

[문제 링크](https://www.acmicpc.net/problem/16535) 

### 성능 요약

메모리: 4012 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍, 수학

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Boyan is playing a computer game. In the beginning there are N balls arranged in a line. Each ball has a number written on it, so that every two consecutive balls have different numbers. The game consists of the following steps:</p>

<ol>
	<li>The player removes a ball from the line.</li>
	<li>While there are consecutive balls with equal numbers, they are automatically removed from the line.</li>
	<li>If there are balls left in the line, go to step 1, otherwise the game ends.</li>
</ol>

<p>The score is the number of balls that are automatically removed. The goal of the game is to maximize the score.</p>

<p>Let’s see an example of a game with 6 balls with numbers {1, 2, 3, 2, 1, 5}.</p>

<ol>
	<li>Boyan removes the ball with number 3. The balls left are {1, 2, 2, 1, 5}.</li>
	<li>Removing the consecutive balls with equal numbers we have {1, 2, 2, 1, 5} -> {1, 1, 5} -> {5}. The ball left is {5}.</li>
	<li>Since there are balls left, we go to step 1.</li>
</ol>

<ol>
	<li>Boyan removes the ball with number 5. The balls left are {}.</li>
	<li>There are no consecutive balls with equal numbers.</li>
	<li>There are no balls left, so the game ends.</li>
</ol>

<p>The number of balls that are automatically removed is 4. It is the maximum possible score for this game. Boyan is playing a lot, but he is still not sure when he is playing optimally. Write program game to help him to find the best score he can achieve.</p>

### 입력 

 <p>The first line contains the positive integer N.</p>

<p>The second line contains N positive integers ─ the numbers written on the balls.</p>

### 출력 

 <p>Print the maximum possible score Boyan can achieve.</p>

