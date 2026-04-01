# [Gold IV] Studying For Exams - 14765 

[문제 링크](https://www.acmicpc.net/problem/14765) 

### 성능 요약

메모리: 109544 KB, 시간: 96 ms

### 분류

수학, 미적분학

### 제출 일자

2026년 4월 2일 00:36:37

### 문제 설명

<p>It is exam time! You have, of course, been spending too much time participating in various programming contests and have not done much studying. Now you have N subjects to study for, but only a limited amount of time before the final exams. You have to decide how much time to allocate to studying each subject, so that your average grade over all N subjects is maximized.</p>

<p>As a seasoned programming contest competitor, you recognize immediately that you can determine the optimal allocation with a computer program. Of course, you have decided to ignore the amount of time you spend solving this problem (i.e. procrastinating).</p>

<p>You have a total of T hours that you can split among different subjects. For each subject i, the expected grade with t hours of studying is given by the function f<sub>i</sub>(t) = a<sub>i</sub>t <sup>2</sup> + b<sub>i</sub>t + c<sub>i</sub>, satisfying the following properties:</p>

<ul>
	<li>f<sub>i</sub>(0) ≥ 0;</li>
	<li>f<sub>i</sub>(T) ≤ 100;</li>
	<li>a<sub>i</sub> < 0;</li>
	<li>f<sub>i</sub>(t) is a non-decreasing function in the interval [0, T].</li>
</ul>

<p>You may allocate any fraction of an hour to a subject, not just whole hours. What is the maximum average grade you can obtain over all n subjects?</p>

### 입력 

 <p>The first line of each input contains the integers N (1 ≤ N ≤ 10) and T (1 ≤ T ≤ 240) separated by a space. This is followed by N lines, each containing the three parameters a<sub>i</sub>, b<sub>i</sub>, and c<sub>i</sub> describing the function f<sub>i</sub>(t). The three parameters are separated by a space, and are given as real numbers with 4 decimal places. Their absolute values are no more than 100.</p>

### 출력 

 <p>Output in a single line the maximum average grade you can obtain. Answers within 0.01 of the correct answer will be accepted.</p>

