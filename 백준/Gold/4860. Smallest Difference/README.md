# [Gold V] Smallest Difference - 4860 

[문제 링크](https://www.acmicpc.net/problem/4860) 

### 성능 요약

메모리: 111224 KB, 시간: 2260 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Given a number of distinct decimal digits, you can form one integer by choosing a non-empty subset of these digits and writing them in some order. The remaining digits can be written down in some order to form a second integer. Unless the resulting integer is 0, the integer may not start with the digit 0.</p>

<p>For example, if you are given the digits 0, 1, 2, 4, 6 and 7, you can write the pair of integers 10 and 2467. Of course, there are many ways to form such pairs of integers: 210 and 764, 204 and 176, etc. The absolute value of the difference between the integers in the last pair is 28, and it turns out that no other pair formed by the rules above can achieve a smaller difference.</p>

### 입력 

 <p>The first line of input contains the number of cases to follow. For each case, there is one line of input containing at least two but no more than 10 decimal digits. (The decimal digits are 0, 1, ..., 9.) No digit appears more than once in one line of the input. The digits will appear in increasing order, separated by exactly one blank space.</p>

### 출력 

 <p>For each test case, write on a single line the smallest absolute difference of two integers that can be written from the given digits as described by the rules above.</p>

