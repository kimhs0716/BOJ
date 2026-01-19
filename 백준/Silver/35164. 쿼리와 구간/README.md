# [Silver I] 쿼리와 구간 - 35164 

[문제 링크](https://www.acmicpc.net/problem/35164) 

### 성능 요약

메모리: 115908 KB, 시간: 184 ms

### 분류

해 구성하기

### 제출 일자

2026년 1월 19일 21:48:49

### 문제 설명

<p>재현이는 다음 두 종류의 쿼리를 처리하는 프로그램을 작성했다.</p>

<ul>
<li><span style="color:#e74c3c;"><code>1</code></span> $l$ $r$: 새로운 구간 $\left( l,r \right)$을 <strong>구간 모음</strong>에 추가한다.</li>
<li><span style="color:#e74c3c;"><code>2</code></span> $a$ $b$: <strong>구간 모음</strong>에 $a$번째로 추가된 구간과 $b$번째로 추가된 구간이 연결되어 있으면 <span style="color:#e74c3c;"><code>1</code></span>, 없으면 <span style="color:#e74c3c;"><code>0</code></span>을 출력한다.</li>
</ul>

<p>처음 <strong>구간 모음</strong>은 비어 있으며, 쿼리로 주어지는 구간은 중복될 수 있다.</p>

<p>어떤 구간 $\left( l_i,r_i \right)$과 구간 $\left( l_j,r_j \right)$에 대해 $l_i<c<r_i$이고 $l_j<c<r_j$를 만족하는 실수 $c$가 존재하면 이 두 구간은 연결되어 있으며, 이 연결 관계는 전이적으로 확장된다. 즉, 구간 $X$와 $Y$가 연결되어 있고 $Y$와 $Z$가 연결되어 있으면 $X$와 $Z$도 연결되어 있다.</p>

<p>재현이는 이 프로그램을 디버깅하던 중, 쿼리들이 적혀 있는 파일을 삭제해 버렸다. 다행히 각 쿼리가 몇 개씩 있는지와 쿼리 실행 결과는 알 수 있었다.</p>

<p>각 쿼리의 개수와 쿼리의 실행 결과가 주어졌을 때, 그 결과를 만들 수 있는 쿼리들을 복원해 보자.</p>

### 입력 

 <p>첫 번째 줄에 <span style="color:#e74c3c;"><code>1</code></span>번 쿼리의 개수 $N(2\le N\le 100\, 000)$과 <span style="color:#e74c3c;"><code>2</code></span>번 쿼리의 개수 $M(1\le M\le 100\, 000)$이 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄부터 $M$줄에 걸쳐 <span style="color:#e74c3c;"><code>2</code></span>번 쿼리에 대한 결과 <span style="color:#e74c3c;"><code>0</code></span> 혹은 <span style="color:#e74c3c;"><code>1</code></span>이 한 줄에 하나씩 주어진다.</p>

### 출력 

 <p>만약 주어진 결과를 만들 수 있다면 첫 번째 줄에 <span style="color:#e74c3c;"><code>1</code></span>을, 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

<p>만약 주어진 결과를 만들 수 있다면 두 번째 줄부터 $N+M$줄에 걸쳐 한 줄에 하나씩 쿼리들을 출력한다.</p>

<p><span style="color:#e74c3c;"><code>1</code></span>번 쿼리의 $l$과 $r$은 $-10^9\le l<r\le 10^9$인 정수여야 하며, <span style="color:#e74c3c;"><code>2</code></span>번 쿼리의 $a$와 $b$는 각각 이전에 출력된 <span style="color:#e74c3c;"><code>1</code></span>번 쿼리의 개수 이하의 정수이며, $a\ne b$여야 한다.</p>

