# [Silver I] Funicular Frenzy - 30494 

[문제 링크](https://www.acmicpc.net/problem/30494) 

### 성능 요약

메모리: 2020 KB, 시간: 12 ms

### 분류

구현, 그리디 알고리즘, 시뮬레이션, 누적 합

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>You are on a skiing trip in the Alps and need to take a funicular.<sup>1</sup> However, there usually is a long queue for the funicular to bring you to the top of the mountain. Being someone who hates wasting time in the morning, you want to find the best moment to start queueing in order to minimize queueing time.</p>

<p>The funicular station is open for \(n\) minutes per day. A carriage transports \(c\) people at once, and one carriage leaves exactly every minute. For every minute the funicular is open today, you know the number of people arriving.</p>

<p>You want to arrive when the station is open, exactly at the start of a minute, like everyone else. Note that you are a sociable person and if there are other people arriving at the same minute as you, you let them go first, after which you stand in the queue.</p>

<p>Calculate at which minute you should arrive to have minimal waiting time, or determine that it is impossible to catch a ride today. If there are two times achieving the same minimal waiting time, give the earliest occasion.</p>

<hr>
<p><sup>1</sup> A funicular is a type of cable railway system laid on a steep slope, where two counterbalanced carriages are attached to opposite ends of a haulage cable, which is looped over a pulley at the upper end of the track.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers \(n\) and \(c\) (\(1 \leq n \leq 10^5\), \(1 \leq c \leq 10^9\)), the number of minutes the funicular is open today and the number of people one funicular carriage takes up the mountain each minute.</li>
	<li>One line with \(n\) integers \(a_0, \dots, a_{n-1}\) (\(0 \leq a_i \leq 10^9\)), the number of new people showing up \(i\) minutes after the funicular opens.</li>
</ul>

### 출력 

 <p>If it is not possible to take the funicular today, output "<code>impossible</code>". Else, output the least number of minutes after opening time you should enter the queue, such that the waiting time is minimized.</p>

