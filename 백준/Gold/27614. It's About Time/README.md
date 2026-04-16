# [Gold V] It's About Time - 27614 

[문제 링크](https://www.acmicpc.net/problem/27614) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

수학, 브루트포스 알고리즘, 임의 정밀도 / 큰 수 연산

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Greg Orian works for the Temporal Innovations for Multiple Earths (TIME) program.  One of his main jobs is determining yearly calendars for the numerous human colonies on various planets (did we mention this problem takes place in $2123$?).  One issue when creating calendars is the schedule for leap days.  On GoE (Good ol' Earth) the rules for leap years are the following:</p>

<ol>
	<li>Any year divisible by $4$ is a leap year, unless</li>
	<li>the year is divisible by $100$ in which case the year is not a leap year, unless</li>
	<li>the year is divisible by $400$ in which case the year is a leap year.</li>
</ol>

<p>Leap days are needed since the $365$ days in the calendar year is not exactly equal to the time for GoE to orbit the sun, which is more like $365.24219$ days (known as the <em>tropical\/</em> year).  This system does a good job in closely approximating the tropical year while also being fairly simple to remember.</p>

<p>While this works fine for GoE, it obviously won't work for planets with different tropical years.  The colonists have enough to adjust to already (lower oxygen levels, colonial in-fighting, people-eating plants, etc.) so Greg wants to come up with rules that are similar to the ones for GoE.  He's hit on the following scheme for finding three values $n_1$, $n_2$ and $n_3$ for determining when a year is a leap year:</p>

<ol>
	<li>The number of days $d$ in a non-leap year is the number of days in a tropical year, rounded to the nearest integer. If the fractional number of days is exactly $0.5$, round the number of days up.</li>
	<li>If you rounded the tropical year down then
	<ol style="list-style-type: lower-alpha;">
		<li>every year divisible by $n_1 > 1$ is a leap year (i.e., you add $1$ day that year), unless</li>
		<li>the year is divisible by $n_2$ (where $n_1 < n_2$ and $n_2$ is a multiple of $n_1$) in which case the year is not a leap year, unless</li>
		<li>the year is divisible by $n_3$ (where $n_2 < n_3 \leq 1\,000$ and $n_3$ is a multiple of $n_2$) in which case the year is a leap year.</li>
	</ol>
	</li>
	<li>If you rounded the tropical year up then the same rules apply except that you subtract $1$ day from leap years instead of adding $1$ (would these be leak years?).</li>
</ol>

<p>For GoE these numbers would be $d = 365, n_1=4, n_2=100$ and $n_3=400$. Given the distance a planet is from its sun (we'll assume a circular orbit), the speed the planet travels around its sun and the number of hours in the planet's day determine the $n_i$ values above to best approximate that planet's year. Note that the best approximation may overestimate or underestimate the actual tropical year length, regardless of the direction of rounding.</p>

### 입력 

 <p>Input contains a single line with three positive integers $r$ $s$ $h$ where $r \leq 1\,000\,000\,000$ is the distance in miles of the planet from the sun, $s \leq 1\,000\,000$ is the speed the planet travels in miles/hour, and $h \leq 1\,000$ is the number of hours in the planet's day. The length of a tropical year is guaranteed to be at least one day ($h$ hours) in length.</p>

### 출력 

 <p>Output the values $n_1$ $n_2$ $n_3$ as described above. It there are multiple values that give the same best approximation, then output any of them.</p>

