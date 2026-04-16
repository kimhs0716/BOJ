# [Gold I] Galaxy collision - 10401 

[문제 링크](https://www.acmicpc.net/problem/10401) 

### 성능 요약

메모리: 14484 KB, 시간: 324 ms

### 분류

그래프 이론, 자료 구조, 그래프 탐색, 집합과 맵, 깊이 우선 탐색, 이분 그래프

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>The Andromeda galaxy is expected to collide with our Milky Way in about 3.8 billion years. The collision will probably be a merging of the two galaxies, with no two stars actually colliding. That is because the distance between stars in both galaxies is so huge. Professor Andrew is building a computational model to predict the possible outcomes of the collision and needs your help! A set of points in the two dimensional plane is given, representing stars in a certain region of the already merged galaxies. He does not know which stars came originally from which galaxy; but he knows that, for this region, if two stars came from the same galaxy, then the distance between them is greater than 5 light years. Since every star in this region comes either from Andromeda or from the Milky Way, the professor also knows that the given set of points can be separated into two disjoint subsets, one comprising stars from Andromeda and the other one stars from the Milky Way, both subsets with the property that the minimum distance between two points in the subset is greater than 5 light years. He calls this a good separation, but the bad news is that there may be many different good separations. However, among all possible good separations there is a minimum number of stars a subset must contain, and this is the number your program has to compute.</p>

<p><img alt="" src="" style="float:right; height:218px; width:342px">For example, the picture illustrates a given set of six points. Professor Andrew cannot tell which stars came from Andromeda, but note that there are four possible good separations: {{1, 2, 4, 5}, {3, 6}}; {{1, 2, 3, 4}, {5, 6}}; {{1, 4, 5}, {2, 3, 6}}; {{1, 3, 4}, {2, 5, 6}}. Therefore, at least two stars must have come from Andromeda, since this is the minimum number of points a subset may have in a good separation.</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 5 × 10<sup>4</sup>) representing the number of points in the set. Each of the next N lines describes a different point with two integers X and Y (1 ≤ X, Y ≤ 5 × 10<sup>5</sup>), indicating its coordinates, in light years. There are no coincident points, and the set admits at least one good separation.</p>

### 출력 

 <p>Output a line with an integer representing the minimum number of points a subset may have in a good separation.</p>

