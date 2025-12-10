# [Silver II] Center of Mass (Large) - 12640 

[문제 링크](https://www.acmicpc.net/problem/12640) 

### 성능 요약

메모리: 2036 KB, 시간: 0 ms

### 분류

기하학, 수학, 물리학, 삼분 탐색

### 제출 일자

2025년 12월 10일 09:41:56

### 문제 설명

<p>You are studying a swarm of <strong>N</strong> fireflies. Each firefly is moving in a straight line at a constant speed. You are standing at the center of the universe, at position (0, 0, 0). Each firefly has the same mass, and you want to know how close the center of the swarm will get to your location (the origin).</p>

<p>You know the position and velocity of each firefly at t = 0, and are only interested in t ≥ 0. The fireflies have constant velocity, and may pass freely through all of space, including each other and you. Let M(t) be the location of the center of mass of the <strong>N</strong> fireflies at time t. Let d(t) be the distance between your position and M(t) at time t. Find the minimum value of d(t), d<sub>min</sub>, and the earliest time when d(t) = d<sub>min</sub>, t<sub>min</sub>.</p>

### 입력 

 <p>The first line of input contains a single integer <strong>T</strong>, the number of test cases. Each test case starts with a line that contains an integer <strong>N</strong>, the number of fireflies, followed by <strong>N</strong> lines of the form</p>

<pre>x y z vx vy vz</pre>

<p>Each of these lines describes one firefly: (x, y, z) is its initial position at time t = 0, and (vx, vy, vz) is its velocity.</p>

<p>Limits</p>

<ul>
	<li>All the numbers in the input will be integers.</li>
	<li>1 ≤ <strong>T</strong> ≤ 100</li>
	<li>The values of x, y, z, vx, vy and vz will be between -5000 and 5000, inclusive.</li>
	<li>3 ≤ <strong>N</strong> ≤ 500</li>
</ul>

### 출력 

 <p>For each test case, output</p>

<pre>Case #X: d<sub>min</sub> t<sub>min</sub></pre>

<p>where <strong>X</strong> is the test case number, starting from 1. Any answer with absolute or relative error of at most 10<sup>-5</sup> will be accepted.</p>

