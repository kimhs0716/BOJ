# [Gold I] Table Tennis - 20255 

[문제 링크](https://www.acmicpc.net/problem/20255) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Alex is attending the first edition of Robotic World Championship of Table Tennis. A competition that have all of the matches having the same rules listed below:</p>

<ul>
	<li>A match shall consist of the best of 7 games, i.e., the results of matches must be 4 games to k, where 0 ≤ k ≤ 3.</li>
	<li>A game shall be won by the player first scoring 11 points unless both players score 10 points, when the game shall be won by the first player subsequently gaining a lead of 2 points. For example, a game can be won at scores like 11-5, 11-9 or 12-10, but not 10-5 or 11-10.</li>
	<li>After each 2 points have been scored the receiving player shall become the serving player and so on until the end of the game, unless both players score 10 points, when the sequences of serving and receiving shall be the same but each player shall serve for only 1 point in turn. That is, the servicing order of the first 20 points is <code>AABBAABBAABBAABBAABB</code>, and will be followed by <code>ABABAB</code>. . . if necessary.</li>
	<li>The player serving first in a game shall receive first in the next game of the match.</li>
</ul>

<p>Experience tells that when two robots clashes into each other, the variances affecting their winning chances can be simplified to who’s serving for the point. This is due to the performances of the robots are physically consistent and won’t be affected mentally.</p>

<p>Alex have listed some of the possible matchups, simplified to the winning chance of each servicing point of the robots, for you. Now it is your job to help him calculate the winning chance of each match for them.</p>

### 입력 

 <p>The first line of the input consists of a single number T, indicating that there will be T test cases following.</p>

<p>Each of the following test case consists of two space-separated real numbers P<sub>A</sub> and P<sub>B</sub> in one line, where P<sub>A</sub> denotes the Robot A’s chance of winning the point when A is serving and P<sub>B</sub> denotes the Robot B’s chance of winning the point when B is serving.</p>

<p>The Robot A always serves first in the very first game of the match.</p>

### 출력 

 <p>For each test case, output one real number in one line: the winning chance of A.</p>

<p>The answer will be considered correct if it is within an absolute error of 10<sup>−8</sup> of the correct answer.</p>

