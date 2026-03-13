# [Gold III] Relocation - 7522 

[문제 링크](https://www.acmicpc.net/problem/7522) 

### 성능 요약

메모리: 2028 KB, 시간: 68 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 3월 13일 13:56:39

### 문제 설명

<p>Emma and Eric are moving to their new house they bought after returning from their honeymoon. Fortunately, they have a few friends helping them relocate. To move the furniture, they only have two compact cars, which complicates everything a bit. Since the furniture does not fit into the cars, Eric wants to put them on top of the cars. However, both cars only support a certain weight on their roof, so they will have to do several trips to transport everything. The schedule for the move is planed like this:</p>

<ol>
	<li>At their old place, they will put furniture on both cars.</li>
	<li>Then, they will drive to their new place with the two cars and carry the furniture upstairs.</li>
	<li>Finally, everybody will return to their old place and the process continues until everything is moved to the new place.</li>
</ol>

<p>Note, that the group is always staying together so that they can have more fun and nobody feels lonely. Since the distance between the houses is quite large, Eric wants to make as few trips as possible.</p>

<p>Given the weights wi of each individual piece of furniture and the capacities C1 and C2 of the two cars, how many trips to the new house does the party have to make to move all the furniture? If a car has capacity C, the sum of the weights of all the furniture it loads for one trip can be at most C.</p>

### 입력 

 <p>The first line contains the number of scenarios. Each scenario consists of one line containing three numbers n, C1 and C2. C1 and C2 are the capacities of the cars (1 ≤ Ci ≤ 100) and n is the number of pieces of furniture (1 ≤ n ≤ 10). The following line will contain n integers w1, . . . , wn, the weights of the furniture (1 ≤ wi ≤ 100). It is guaranteed that each piece of furniture can be loaded by at least one of the two cars.</p>

### 출력 

 <p>The output for every scenario begins with a line containing “Scenario #i:”, where i is the number of the scenario starting at 1. Then print a single line with the number of trips to the new house they have to make to move all the furniture. Terminate each scenario with a blank line.</p>

