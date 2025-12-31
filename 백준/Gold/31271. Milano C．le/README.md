# [Gold II] Milano C.le - 31271 

[문제 링크](https://www.acmicpc.net/problem/31271) 

### 성능 요약

메모리: 8348 KB, 시간: 48 ms

### 분류

이분 탐색, 자료 구조, 그리디 알고리즘, 가장 긴 증가하는 부분 수열 문제, 트리를 사용한 집합과 맵, 집합과 맵

### 제출 일자

2025년 12월 31일 15:48:25

### 문제 설명

<p>Silvia is at the Milano Centrale railway station and she noticed that the station has a lot of platforms. She thought that there are too many of them, so she decided to check how many of them are actually needed.</p>

<p>Silvia also noticed an interesting fact that holds at this station: the schedule of arrivals and departures repeats every two days, and additionally, the schedule is such that all $n$ trains arrive at the station on one day, and leave the station on the other day. Note that in this way no train will leave before all trains have arrived.</p>

<p>The platforms at the station are long enough so that all $n$ trains can be lined up one after another on the same platform. However, if train $x$ enters the platform first, and then train $y$, then train $x$ cannot leave the platform before train $y$.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c6c4415b-3f02-48ff-bcde-98601a54ed73/-/preview/" style="width: 400px; height: 165px;"></p>

<p style="text-align: center;">The illustration shows a possible train schedule on the platforms in the second sample test.</p>

<p style="text-align: center;">The labels on the train '$i$ : $a_i$/$b_i$' denote that the $i$-th train will arrive $a_i$-th at the station on the first day, and leave the station $b_i$-th on the second day.</p>

<p style="text-align: center;">The train ($2$ : $1$/$2$) cannot leave the platform before the train ($4$ : $5$/$1$).</p>

<p>Silvia is interested in what is the minimum number of platforms needed so that all trains can be lined up on the platforms, without the possibility that a train cannot leave the platform because there is a train in front of it that has not yet left.</p>

### 입력 

 <p>The first line contains an integer $n$ ($1 ≤ n ≤ 2 \cdot 10^5$), the number of trains.</p>

<p>The second line contains $n$ integers $a_i$, ($1 ≤ a_i ≤ n$, $a_i \ne a_j$ for all $i \ne j$), which denote that the $i$-th train arrives at the station as the $a_i$-th train on the first day. The sequence $(a_i)$ is a permutation.</p>

<p>The third line contains $n$ integers $b_i$, ($1 ≤ b_i ≤ n$, $b_i \ne b_j$ for all $i \ne j$), which denote that the $i$-th train leaves the station as the $b_i$-th train on the second day. The sequence $(b_i)$ is a permutation.</p>

### 출력 

 <p>In the first and only line you should output the minimum number of platforms needed.</p>

