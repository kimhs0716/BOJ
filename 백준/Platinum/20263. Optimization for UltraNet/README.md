# [Platinum IV] Optimization for UltraNet - 20263 

[문제 링크](https://www.acmicpc.net/problem/20263) 

### 성능 요약

메모리: 20596 KB, 시간: 180 ms

### 분류

자료 구조, 그래프 이론, 분리 집합, 최소 스패닝 트리

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>The UltraNet company provides network connectivity for all cities in a country. For a pair of cities, they are either directly connected or indirectly connected. A city i and another city j are directly connected if a cable with a symmetrical bandwidth of b<sub>i,j</sub> = b<sub>j,i</sub> is wired between them. For two cities that are not directly connected, at least one path between the two cities exists. In the current UltraNet, more than one path is possibly available for a city pair.</p>

<p>The current UltraNet is perfectly working, while the maintenance fee of each cable is costly. Energy conservation is another concern. The energy consumption of a cable is proportional to its bandwidth. Therefore, the company has an optimization plan to reorganize the network with the policies in the following order:</p>

<ol>
	<li>The number of cables should be minimized without sacrificing the connectivity of the whole UltraNet. In other words, exactly one path between every city pair should be satisfied.</li>
	<li>If there is more than one way to minimize the number of cables, the bottleneck of the whole network should be maximized. The bottleneck of a network is determined by the city pair with the narrowest bandwidth, and the bandwidth of a city pair (i, j), b'<sub>i,j</sub>, is determined by the cable with the narrowest bandwidth on the only path from i to j.</li>
	<li>If there is still more than one way to meet the above two points, the total energy consumption of the network should be minimized. In other words, the sum of bandwidths of the remaining cables should be minimized.</li>
</ol>

<p>Your task is to help UltraNet optimize the network and then output the sum of the bandwidths among all city pairs in the optimized network. For optimizing the following example, the three cables in dotted will be discarded. In the resulting network, the bottleneck is 3, the sum of bandwidths of the remaining four cables is 6 + 3 + 8 + 4 = 21, and the sum of the bandwidths among all city pairs is \(\sum_{i=1}{^n-1}\sum_{j=i+1}^{n}\)b'<sub>i,j</sub> = 6 + 4 + 6 + 3 + 4 + 8 + 3 + 4 + 3 + 3 = 44.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 212px; height: 183px;"></p>

### 입력 

 <p>Each test case begins with two integers n and m, denoting numbers of cities and cables, respectively. Then, m lines will follow for specifying the m cables. Each of the m lines contains three positive integers, i, j, and b<sub>i,j</sub>, denoting that a cable with a bandwidth of b<sub>i,j</sub> directly connects the city pair (i, j), where the cities are numbered from 1 to n, and i < j since b<sub>i,j</sub> = b<sub>j,i</sub>. No more than one cable will be available between every city pair in the current network. In addition, the bandwidths of all cables are distinct; no two cables have the same bandwidth rating.</p>

### 출력 

 <p>The output is a single integer that is the sum of the bandwidths of all city pairs in the optimized network.</p>

