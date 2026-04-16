# [Platinum V] Arrested Development - 31949 

[문제 링크](https://www.acmicpc.net/problem/31949) 

### 성능 요약

메모리: 41084 KB, 시간: 472 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>You are now in charge of two programming interns, and you must develop a large system. There are a number of tasks that need to be completed by the end of the summer. You know how long each intern will take to complete each task, in minutes.</p>

<p>Compute the minimum number of minutes it will take to complete all tasks for development of the system, assuming that the two interns are the only developers, that they work independently and concurrently, that they do not share tasks, and that the amount of time it takes an intern to complete all their tasks is the sum of the number of minutes it takes to do each task one after the other.</p>

### 입력 

 <p>The first line of input contains a single integer $n$ ($1 \le n \le 50$), which is the number of tasks.</p>

<p>Each of the next $n$ lines contains two integers $a$ and $b$ ($1 \le a,b \le 10^5$). Each line represents a single task, where $a$ is the number of minutes it will take the first intern to complete the task, and $b$ is the number of minutes it will take the second intern to complete the task.</p>

### 출력 

 <p>Output a single integer, which is the minimum number of minutes needed to complete the development project.</p>

