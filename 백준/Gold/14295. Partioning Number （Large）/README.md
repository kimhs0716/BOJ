# [Gold II] Partioning Number (Large) - 14295 

[문제 링크](https://www.acmicpc.net/problem/14295) 

### 성능 요약

메모리: 2020 KB, 시간: 96 ms

### 분류

수학, 브루트포스 알고리즘

### 제출 일자

2026년 4월 9일 12:13:45

### 문제 설명

<p>Shekhu has N balls. She wants to distribute them among one or more buckets in a way that satisfies all of these constraints:</p>

<ol>
	<li>The numbers of balls in the buckets must be in non-decreasing order when read from left to right.</li>
	<li>The leftmost bucket must be non-empty and the number of balls in the leftmost bucket must be divisible by D.</li>
	<li>The difference (in number of balls) between <em>any</em> two buckets (not just any two adjacent buckets) must be less than or equal to 2.</li>
</ol>

<p>How many different ways are there for Shekhu to do this? Two ways are considered different if the lists of numbers of balls in buckets, reading left to right, are different.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, T.</p>

<p>T test cases follow. Each test case consists of one line with two integers N and D, as described above.</p>

<p>Limits</p>

<ul>
	<li>1 ≤ T ≤ 100.</li>
	<li>1 ≤ D ≤ 100.</li>
	<li>1 ≤ N ≤ 10<sup>5</sup>.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the answer, as described above.</p>

