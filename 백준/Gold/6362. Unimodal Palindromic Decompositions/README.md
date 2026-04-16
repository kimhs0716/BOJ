# [Gold III] Unimodal Palindromic Decompositions - 6362 

[문제 링크](https://www.acmicpc.net/problem/6362) 

### 성능 요약

메모리: 2392 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>A sequence of positive integers is Palindromic if it reads the same forward and backward. For example:</p>

<ul>
	<li>23 11 15 1 37 37 1 15 11 23</li>
	<li>1 1 2 3 4 7 7 10 7 7 4 3 2 1 1</li>
</ul>

<p>A Palindromic sequence is Unimodal Palindromic if the values do not decrease up to the middle value and then (since the sequence is palindromic) do not increase from the middle to the end For example, the first example sequence above is NOT Unimodal Palindromic while the second example is.</p>

<p>A Unimodal Palindromic sequence is a Unimodal Palindromic Decomposition of an integer N, if the sum of the integers in the sequence is N. For example, all of the Unimodal Palindromic Decompositions of the first few integers are given below:</p>

<ol>
	<li>(1)</li>
	<li>(2), (1 1)</li>
	<li>(3), (1 1 1)</li>
	<li>(4), (1 2 1), (2 2), (1 1 1 1)</li>
	<li>(5), (1 3 1), (1 1 1 1 1)</li>
	<li>(6), (1 4 1), (2 2 2), (1 1 2 1 1), (3 3), (1 2 2 1), ( 1 1 1 1 1 1)</li>
	<li>(7), (1 5 1), (2 3 2), (1 1 3 1 1), (1 1 1 1 1 1 1)</li>
	<li>(8), (1 6 1), (2 4 2), (1 1 4 1 1), (1 2 2 2 1), (1 1 1 2 1 1 1), (4 4), (1 3 3 1), (2 2 2 2), (1 1 2 2 1 1), (1 1 1 1 1 1 1 1)</li>
</ol>

<p>Write a program, which computes the number of Unimodal Palindromic Decompositions of an integer.</p>

### 입력 

 <p>Input consists of a sequence of positive integers, one per line ending with a 0 (zero) indicating the end.</p>

### 출력 

 <p>For each input value except the last, the output is a line containing the input value followed by a space, then the number of Unimodal Palindromic Decompositions of the input value.</p>

