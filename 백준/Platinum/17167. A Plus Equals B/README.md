# [Platinum II] A Plus Equals B - 17167 

[문제 링크](https://www.acmicpc.net/problem/17167) 

### 성능 요약

메모리: 29200 KB, 시간: 68 ms

### 분류

수학, 애드 혹, 해 구성하기

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>$A+B$ is a problem used to test one's basic knowledge for competitive programming. Here is yet another boring variation of it.</p>

<p>You have two integers, $A$ and $B$. You want to make them equal. To do so, you can perform several steps, where each step is one of the following:</p>

<ul>
	<li>$A$ += $A$</li>
	<li>$A$ += $B$</li>
	<li>$B$ += $A$</li>
	<li>$B$ += $B$</li>
</ul>

<p>Unfortunately, $A+B$ is a hard problem for us, so you are allowed to make at most 5000 steps.</p>

### 입력 

 <p>In the first line, two space-separated integers $A$ and $B$ are given. These are the initial values of the variables $A$ and $B$.</p>

### 출력 

 <p>In the first line, print a single integer $n$ ($0 \le n \le 5\,000$) denoting the number of steps.</p>

<p>In the next $n$ lines, print one of the following strings to denote your desired operation: <kbd>A+=A</kbd>, <kbd>A+=B</kbd>, <kbd>B+=A</kbd>, <kbd>B+=B</kbd>.</p>

<p>Any sequence of steps that yields the desired result will be judged correct.</p>

