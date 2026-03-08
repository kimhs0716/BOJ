# [Gold III] Shops - 10294 

[문제 링크](https://www.acmicpc.net/problem/10294) 

### 성능 요약

메모리: 18492 KB, 시간: 76 ms

### 분류

다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2026년 3월 8일 21:30:23

### 문제 설명

<p>In a country fair, the shopping area is divided into N x 5 cells with N columns and 5 rows. (1 <= N <= 50,000) Each cell is out for rent. You have survey the site and, for any cell, calculate the estimated profit if you rent that cell. Ideally, as you have unlimited money for renting, you would like to rent all the cells, but the fair organizer prevents any company to rent any two cells which are adjacent. (Two cells are adjacent if they are next to each other in the up, down, left and right direction.) </p>

<p>Your task is to write a program that calculate the maximum profit that you can get by renting cells that are all non-adjacent. </p>

### 입력 

 <p>The first line of the input denotes an integer T, (1 <= T <= 5) the number of test cases. Then T test cases follows in the format described next. </p>

<ul>
	<li>The first line of the test case contains an integer N (1 <= N <= 50,000)</li>
	<li>The next 5 lines shows the profits on all the cells. That is, line 1+i contains N nonnegative integers representing the profits on all cells in row i. The profits will be at most 10,000. </li>
</ul>

### 출력 

 <p>For each test case, output one integer which is the maximum total profit that you can get by renting cells which are non-adjacent.</p>

