# [Gold V] The Triangle Game - 14549 

[문제 링크](https://www.acmicpc.net/problem/14549) 

### 성능 요약

메모리: 2024 KB, 시간: 16 ms

### 분류

브루트포스 알고리즘, 백트래킹

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="height:219px; width:434px"></p>

<p>In the triangle game you start off with six triangles numbered on each edge, as in the example above. You can slide and rotate the triangles so they form a hexagon, but the hexagon is only legal if edges common to two triangles have the same number on them. You may not flip any triangle over. Two legal hexagons formed from the six triangles are illustrated below.</p>

<p style="text-align: center;"><img alt="" src="" style="height:228px; width:510px"></p>

<p>The score for a legal hexagon is the sum of the numbers on the outside six edges.</p>

<p>Your problem is to find the highest score that can be achieved with any six particular triangles.</p>

### 입력 

 <p>The input file contain one or more data sets. Each data set is a sequence of six lines with three integers from 1 to 100 separated by blanks on each line. Each line contains the numbers on the triangles in clockwise order. Data sets are separated by a line containing only an asterisk. The last data set is followed by a line containing only a dollar sign.</p>

### 출력 

 <p>For each input data set, the output is a line containing only the word "none" if there are no legal hexagons or the highest score if there is a legal hexagon.</p>

