# [Platinum IV] 잘못 작성한 요세푸스 코드 - 1215 

[문제 링크](https://www.acmicpc.net/problem/1215) 

### 성능 요약

메모리: 113400 KB, 시간: 100 ms

### 분류

수학, 정수론

### 제출 일자

2026년 3월 27일 11:16:38

### 문제 설명

<p>요세푸스 문제는 아래와 같이 풀 수 있다.</p>

<pre class="brush:c++; toolbar:false;">r := 0;
for i from 1 to n do
    r := (r + k) mod i;
return r;</pre>

<p>하지만 상근이는 코드를 잘못 읽고 아래와 같이 작성했다.</p>

<pre class="brush:c++; toolbar:false;">r := 0;
for i from 1 to n do
    r := r + (k mod i);
return r;</pre>

<p>n과 k가 주어졌을 때, 상근이의 잘못 작성한 소스를 실행시킨 결과를 출력하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫 줄에 n과 k가 주어진다. (1 ≤ n, k ≤ 10<sup>9</sup>)<br>
 </p>

### 출력 

 <p>첫째 줄에 주어진 n과 k로 상근이의 잘못 작성한 소스의 결과를 출력한다.</p>

