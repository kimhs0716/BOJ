# [Gold II] Triangle - 32840 

[문제 링크](https://www.acmicpc.net/problem/32840) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 기하학, 정수론, 유클리드 호제법, 다각형의 넓이

### 제출 일자

2026년 04월 17일 01:18:14

### 문제 설명

<p>There is a triangle whose coordinates of three vertices $A$, $B$, and $C$ are all integers. If you select a point on each side of the triangle whose coordinates are integers and connect those points, a new triangle is created. When creating a new triangle, no vertex of the given triangle can be selected as a vertex of the new triangle.</p>

<p>Depending on which points you select and connect, the area of the newly created triangle may be large or small.</p>

<p>You are to write a program that finds out the largest and smallest areas of the newly created triangle if they exist.</p>

<p>For example, as shown in the figure below, if the coordinates of the three vertices of the given triangle are $(4, 8)$, $(-8, -1)$, and $(7, -7)$, the yellow triangle shown in Fig. L.1(a) has the largest area among those that satisfy the condition, and the blue triangle shown in Fig. L.1(b) has the smallest area.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 567px; height: 300px;"></p>

<p>There may not be a point on any side of the given triangle whose coordinates are integers, in which case the triangle you are looking for does not exist.</p>

<p>It is guaranteed that the three points of the given input are not on a straight line.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of a line containing six integers that are the $(x, y)$-coordinates of the three vertices $A = \left(A_x, A_y\right)$, $B = \left(B_x, B_y\right)$, and $C = \left(C_x, C_y\right)$ of a triangle, which $A_x$, $A_y$, $B_x$, $B_y$, $C_x$, and $C_y$ are given in that order. Each value of the coordinates is an integer between $-10^9$ and $10^9$, inclusive.</p>

### 출력 

 <p>Your program is to write to standard output. Let the area of the newly created triangle with the largest area be $S_\max$, and the area of the triangle with the smallest area be $S_\min$. If such triangles can be found, print $2S_\max$ and $2S_\min$ in that order, where both $2S_\max$ and $2S_\min$ are positive integers. If such triangles cannot be found, print <code>-1</code>.</p>

