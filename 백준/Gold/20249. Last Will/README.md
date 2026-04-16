# [Gold III] Last Will - 20249 

[문제 링크](https://www.acmicpc.net/problem/20249) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 기하학, 정수론, 유클리드 호제법

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>David is a farmer and has a large farm. The shape of the farm is a square. A sqaure is a quadrilaterial that has four equal sides and four equal angles. The length of any side of David’s farm is one kilometer, so the area of his farm is slightly greater than the total area of 140 standard football fields.</p>

<p>David is old and very ill. He feels that his days are numbered. Worrying that his spouse Dora and their three children, Alice, Bob, and Cliff, will have a dispute over the ownership of the farm after he passes away, he plans to divide the farm into four parts, and then to allocate each part to one of his family members. He decides to write his last will as follows.</p>

<ol>
	<li>
	<p>Assume that the shape of the farm is a sqaure ABCD where A = (0, 0), B = (1, 0), C = (1, 1), D = (0, 1).</p>
	</li>
	<li>
	<p>Let E = (0.5, 0), F = (1, 0.5), G = (0.5, 1), H = (0, 0.5) be the midpoints of <span class="overline">AB</span>, <span class="overline">BC</span>, <span class="overline">CD</span>, <span class="overline">DA</span>, respectively.</p>
	</li>
	<li>
	<p>Let area(PRQS) to denote the area of the quadrilaterial PQRS.</p>
	</li>
	<li>
	<p>Please find a point X <em>strictly inside</em> the square ABCD such that</p>

	<p style="text-align: center;">area(AEXH) : area(BF XE) : area(CGXF) = p : q : r</p>

	<p>Note that X cannot be on the boundary of the square ABCD.</p>
	</li>
	<li>
	<p>Allocate the land in AEXH, BF XE, CGXF, DHXG to Alice, Bob, Cliff and Dora, respectively.</p>
	</li>
</ol>

<p>David is still adjusting the numbers p, q, r, and his lawyer, Reed, has to read David’s last will carefully. Reed finds that it is impossible to find such point X if David gives an improper set of the numbers such as p = 1, q = 2, r = 1. However, there are proper sets of the numbers p, q, r that allow us to find the point X satisfying David’s last will. For instance, let p : q : r = 2 : 3 : 2, the following figure shows a possible position of X.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 190px; height: 187px;"></p>

<p style="text-align: center;">Figure 2: area(AEXH) : area(BF XE) : area(CGXF) = 2 : 3 : 2</p>

<p>Please write a program to help Reed to determine whether it is possible to find a point X satisfying David’s last will for a given set of numbers p, q, r. If possible, please output one possible position of X to Reed.</p>

### 입력 

 <p>The input contains one line only. The line contains three space-separated positive integers p, q, r.</p>

### 출력 

 <p>If there does not exist a point X satisfying David’s last will, then output -1. Otherwise, output two irreducible fractions x and y such that (x, y) can be the point X satisfying David’s last will. You must output an irreducible fraction t = n d as n/d with a positive denominator and use exactly one space to separate x and y.</p>

<p>Note: the numerator and the denominator of any irreducible fraction are integers and do not have common divisors other than 1 and −1.</p>

