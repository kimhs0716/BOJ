# [Silver I] Two Mysterious Alphabets from a Tree - 9775 

[문제 링크](https://www.acmicpc.net/problem/9775) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Your task is to extract $2$ alphabets from a <strong>binary</strong> tree which is composed of unsigned integers respecting the following rules. Let $n$ be the height of a tree. At the level $k$ ($1≤ k ≤ n$), the tree contains $k$ of nodes and each node has $2$ children nodes (except the leaf nodes at the level n which have no children). See the example below to understand the tree formation. Some nodes may have $2$ parent nodes.</p>

<pre>    <span style="color:#b02418;"><strong>1</strong></span>
   / <span style="color:#b02418;"><strong>\</strong></span>
  4   <span style="color:#b02418;"><strong>5</strong></span>
 / \ / <span style="color:#b02418;"><strong>\</strong></span>
7   8   <span style="color:#b02418;"><strong>9</strong></span></pre>

<p>You need to walk in a tree on the path that has a maximum summation (e.g., $1 + 5 + 9 = 15$). Numbers in each summation cannot cross into different links (e.g., $5+7$ is illegal). Then, your intermediate task is to calculate $2$ <em>numbers</em> for alphabet extraction. <em>The first number</em> is calculated from $\sum_{i=1}^{n}{i^2}$ where $i$ is a number along the maximum summation path and $n$ is the height of a tree. <em>The second number</em> is a summation of the maximum path ($\sum_{i=1}^{n}{i}$). Regarding to the example above, the first number $= 1 + 25 + 81 = 107$ and the second number $= 1 + 5 + 9 = 15$.</p>

<p>Finally, these two numbers are transformed into two lower case alphabets from ‘a’ to ‘z’ respectively, where ‘a’ is used for $0$ and ‘z’ is used for $25$. Since there are only $26$ alphabets, a number greater than $25$ will reuse the same set of alphabets. For example, $107$ = ‘d’ and $15$ = ‘p’ (that is, the first alphabet ‘a’ = $0$, or $26$, or $52$ etc).</p>

<p>Write a program to find the $2$ mysterious alphabets from a given tree.</p>

### 입력 

 <p>The first line of input contains the height ($n$) of a tree ($0<n< 100$). The second line contains unsigned integer numbers ($i$) in each level of a tree ($0<i<100$), consecutively. Assume that there is only one maximum path in a tree.</p>

### 출력 

 <p>The first line contains two integer calculated from the rules above, and the second line contains $2$ decoded alphabets.</p>

