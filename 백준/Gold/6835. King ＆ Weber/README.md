# [Gold II] King & Weber - 6835 

[문제 링크](https://www.acmicpc.net/problem/6835) 

### 성능 요약

메모리: 23904 KB, 시간: 400 ms

### 분류

이분 그래프, 그래프 이론

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>It is easy to get lost in Kitchener-Waterloo. Many streets that are mostly parallel actually intersect, sometimes multiple times. The best-known example is King and Weber Streets. Other examples include Westmount and Fischer-Hallman, University and Erb, and Queen and Highland.</p>

<p>Navigation is easier in cities that respect the “Manhattan Assumption”: all streets are straight lines in a Euclidean plane, and any two streets are either parallel or perpendicular to each other. Visitors to Manhattan are cautioned that even Manhattan itself does not fully satisfy this assumption.</p>

<p>The input to your program will be a sequence of observations followed by a sequence of queries for a particular city. An observation asserts either that two streets are parallel, or that they intersect. A query asks whether two streets are parallel, or whether they intersect, provided the city satisfies the Manhattan Assumption.</p>

### 입력 

 <p>The first line of input contains two integers m and n (1 ≤ m, n ≤ 100000). Each of the following m lines contains an observation. Each observation consists of three words separated by spaces: the two street names, and either the word parallel or the word intersect. Each street name is a sequence of no more than 100 uppercase or lowercase letters. The observations are followed by n queries, each on a separate line. A query consists of two street names separated by a space.</p>

### 출력 

 <p>If it is impossible for the city to conform to both the Manhattan Assumption and the specified observations, output a single line containing the word <code>Waterloo</code>. Otherwise, output n lines containing the answers to the n queries. Each answer should be one of the following three words: <code>parallel</code>, <code>intersect</code>, <code>unknown</code>. If the two streets queried are parallel in every city satisfying the given observations and the Manhattan Assumption, the output should be parallel. If they are perpendicular in every such city, the output should be intersect. If they are parallel in some such city and perpendicular in another such city, the output should be unknown.</p>

