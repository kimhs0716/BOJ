# [Gold IV] Bovine Bridge Battle - 5973 

[문제 링크](https://www.acmicpc.net/problem/5973) 

### 성능 요약

메모리: 115088 KB, 시간: 652 ms

### 분류

자료 구조, 애드 혹, 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Each of Farmer John's N (4 <= N <= 1,000) cows is patiently waiting in the main pasture with cow i at point with integer coordinates (X_i, Y_i) (-1,000,000,000 <= X_i <= 1,000,000,000; -1,000,000,000 <= Y_i <= 1,000,000,000).</p>

<p>The cows wish to form into groups of four in order to play Bridge, their new favorite card game. Each group must satisfy an important constraint: four cows are allowed to team up if and only if there exists some point X somewhere in the plane (and not coincident with any of the four points of the potential group of four) such that rotating any of the group's cows 180 degrees about that point X gives the position of some other cow in the group.</p>

<p>Please help the cows determine the number of sets of four cows that can form a Bridge group.</p>

<p>By way of example, suppose eight cows are standing at eight points:</p>

<pre>                  |
                 f*
                  |             a = (-3, 1)    e = (-1, 1)
           b*     |             b = (-2, 2)    f = ( 0, 3)
        a      e  |             c = (-3, 0)    g = ( 2, 0)
         *     *  |             d = (-2, 0)    h = ( 3, 0)
         c  d     |     g  h
---------*--*-----+-----*--*---------
                  |</pre>

<p>Then the three legal sets of four cows are {a, b, e, d} (they rotate around point (-2, 1)), {b, c, e, f} (around the point (-1.5, 1.5)), and {c, d, g, h} (around (0,0)).</p>

<p>The supplied locations of the cows given are all distinct, although they are supplied in no particular order. Furthermore, the answer will fit into a signed 32-bit integer.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains two space-separated integers: X_i and Y_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of sets of 4 cows that form valid groups for bridge.</li>
</ul>

<p> </p>

