# [Platinum V] Ellipse Intersection - 22770 

[문제 링크](https://www.acmicpc.net/problem/22770) 

### 성능 요약

메모리: 109240 KB, 시간: 5940 ms

### 분류

미적분학, 기하학, 수학

### 제출 일자

2024년 9월 28일 14:09:41

### 문제 설명

<p>Recently the astronomers have discovered a peculiar pair of planets, named A and B. As we know, a planet usually moves in an ellipse orbit, so do A and B. But their orbits are quite special:</p>

<ol>
	<li>Their orbits are in the same plane and share the same center;</li>
	<li>The segments formed by joining their own focuses respectively are perpendicular to each other.</li>
</ol>

<p>If we denote the center as point O, and the focuses of orbit A as F<sub>1</sub> and F<sub>2</sub>, then we can build Cartesian coordinates, with point O being the origin, and the line through F<sub>1</sub> and F<sub>2</sub> being the x-axis.</p>

<p>Here is a sample:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6e4ec227-336a-4147-a533-85b2d5afa4e6/-/preview/" style="width: 201px; height: 202px;"></p>

<p style="text-align: center;">Figure 1: Sample orbits</p>

<p>As the astronomers would like to know more about the planets, they decide to calculate the intersection area first. But unfortunately calculating the intersection area is so complex and beyond their ability, so they have to turn to you, a talent of programming.</p>

<p>You are given the description of two ellipse orbits satisfying the conditions above, and required to calculate their intersection area.</p>

### 입력 

 <p>Input may contain multiple test cases. The first line is a positive integer n (n ≤ 100), denoting the number of test cases below. Each case is composed of two lines, the first one is the description of orbit A, and the second one the description of orbit B. Each description contains two positive integers, a and b (a, b ≤ 100), denoting the ellipse equation x<sup>2</sup>/a<sup>2</sup> + y<sup>2</sup>/b<sup>2</sup> = 1. It is guaranteed that the focuses of orbit A are on x-axis, and the focuses of orbit B are on y-axis.</p>

### 출력 

 <p>For each test case, output one line containing a single real number, the area of the intersection, with an error up to 0.001.</p>

