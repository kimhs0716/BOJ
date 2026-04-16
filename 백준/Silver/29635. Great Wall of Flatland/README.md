# [Silver I] Great Wall of Flatland - 29635 

[문제 링크](https://www.acmicpc.net/problem/29635) 

### 성능 요약

메모리: 2172 KB, 시간: 0 ms

### 분류

자료 구조, 기하학, 집합과 맵, 해시를 사용한 집합과 맵

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Once Emperor of Flatland Hu Shiandgi decided to strengthen his great empire and commanded to build the Great Wall of Flatland. At that moment Flatland consisted of a number of Warring Kingdoms. Each of the them had triangular shape and they did not overlap with each other. Along the perimeter of each of them there were unbreakable walls, and in every corner of each kingdom there was a guard tower.</p>

<p>The land had been distributed by the previous ruler of Flatland in such a manner that from any of the towers on a clear day one could see any other. As we know from the writings of the Great Flatland Mathematicians this is possible only in the case when there are no three towers on a same straight line.</p>

<p>In addition, since the imperial tax office had to collect taxes from all the Warring Kingdoms, and tax officers had to carry with them large sums of money, the country was constructed in such a way that the tax officer could get from any of the Kingdoms to any other using only unbreakable walls, possibly of different Kingdoms.</p>

<p>To find out how much money should be allocated for the construction of the Great Wall of Flatland, Hu Shiandgi needs to know the total length of all unbreakable walls, which separate the territory of some Warring Kingdom from the territory not belonging to Flatland.</p>

### 입력 

 <p>First line of the input file contains an integer number $m$ --- the number of Warring Kingdoms ($1 \le m \le 1000$). Each of the following $m$ lines contains six numbers $x_1$, $y_1$, $x_2$, $y_2$, $x_3$, $y_3$ --- coordinates of vertices of triangle that describes the area of the corresponding Warring Kingdom. All coordinates are integer and do not exceed $10^4$ by absolute value.</p>

### 출력 

 <p>Output the length of The Great Wall of Flatland. You answer should be accurate up to $10^{-4}$.</p>

