# [Gold II] Sum of digits - 13245 

[문제 링크](https://www.acmicpc.net/problem/13245) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

조합론, 수학

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>It is easy to compute the sum of the numbers in the sequence from 0 to n with the formula n*(n+1)/2. That is: 0 + 1 + 2 + .... + n = n*(n+1)/2</p>

<p>This problem is a bit harder: what about the sum of the digits in the sequence [0, 1, ..., n]?</p>

<p>Write a program that computes the sum of the digits that can be found when counting from 0 to n.</p>

<p>For n = 15 we want to sum the digits that appear in the sequence [0, 1, 2, ..., 14, 15].</p>

<p>The result is: 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 + 0 +1 + 1 + 1 + 2 + 1 + 3 + 1 + 4 + 1 + 5 = 66</p>

### 입력 

 <p>A single line with an integer n (1 ≤ n ≤ 10<sup>16</sup>)</p>

### 출력 

 <p>A single line with the sum of digits in the sequence [0, 1, ..., n-1, n]</p>

