# [Gold II] Two Ends - 4080 

[문제 링크](https://www.acmicpc.net/problem/4080) 

### 성능 요약

메모리: 9996 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>In the two-player game “Two Ends”, an even number of cards is laid out in a row. On each card, face up, is written a positive integer. Players take turns removing a card from either end of the row and placing the card in their pile. The player whose cards add up to the highest number wins the game. Now one strategy is to simply pick the card at the end that is the largest — we’ll call this the greedy strategy. However, this is not always optimal, as the following example shows: (The first player would win if she would first pick the 3 instead of the 4.)</p>

<p>3 2 10 4</p>

<p>You are to determine exactly how bad the greedy strategy is for different games when the second player uses it but the first player is free to use any strategy she wishes.</p>

### 입력 

 <p>There will be multiple test cases. Each test case will be contained on one line. Each line will start with an even integer n followed by n positive integers. A value of n = 0 indicates end of input. You may assume that n is no more than 1000. Furthermore, you may assume that the sum of the numbers in the list does not exceed 1,000,000.</p>

### 출력 

 <p>For each test case you should print one line of output of the form:</p>

<pre>In game m, the greedy strategy might lose by as many as p points.</pre>

<p>where m is the number of the game (starting at game 1) and p is the maximum possible difference between the first player’s score and second player’s score when the second player uses the greedy strategy. When employing the greedy strategy, always take the larger end. If there is a tie, remove the left end.</p>

