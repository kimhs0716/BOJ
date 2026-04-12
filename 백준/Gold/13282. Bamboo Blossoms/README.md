# [Gold I] Bamboo Blossoms - 13282 

[문제 링크](https://www.acmicpc.net/problem/13282) 

### 성능 요약

메모리: 3056 KB, 시간: 1552 ms

### 분류

수학, 그리디 알고리즘, 정수론, 소수 판정, 에라토스테네스의 체, 비트 집합

### 제출 일자

2025년 7월 14일 16:55:07

### 문제 설명

<p>The bamboos live for decades, and at the end of their lives, they flower to make their seeds. Dr. ACM, a biologist, was fascinated by the bamboos in blossom in his travel to Tsukuba. He liked the flower so much that he was tempted to make a garden where the bamboos bloom annually. Dr. ACM started research of improving breed of the bamboos, and finally, he established a method to develop bamboo breeds with controlled lifetimes. With this method, he can develop bamboo breeds that flower after arbitrarily specified years.</p>

<p>Let us call bamboos that flower k years after sowing "k-year-bamboos." k years after being sowed, k-year-bamboos make their seeds and then die, hence their next generation flowers after another k years. In this way, if he sows seeds of k-year-bamboos, he can see bamboo blossoms every k years. For example, assuming that he sows seeds of 15-year-bamboos, he can see bamboo blossoms every 15 years; 15 years, 30 years, 45 years, and so on, after sowing.</p>

<p>Dr. ACM asked you for designing his garden. His garden is partitioned into blocks, in each of which only a single breed of bamboo can grow. Dr. ACM requested you to decide which breeds of bamboos should he sow in the blocks in order to see bamboo blossoms in at least one block for as many years as possible.</p>

<p>You immediately suggested to sow seeds of one-year-bamboos in all blocks. Dr. ACM, however, said that it was difficult to develop a bamboo breed with short lifetime, and would like a plan using only those breeds with long lifetimes. He also said that, although he could wait for some years until he would see the first bloom, he would like to see it in every following year. Then, you suggested a plan to sow seeds of 10-year-bamboos, for example, in different blocks each year, that is, to sow in a block this year and in another block next year, and so on, for 10 years. Following this plan, he could see bamboo blossoms in one block every year except for the first 10 years. Dr. ACM objected again saying he had determined to sow in all blocks this year.</p>

<p>After all, you made up your mind to make a sowing plan where the bamboos bloom in at least one block for as many consecutive years as possible after the first m years (including this year) under the following conditions:</p>

<ul>
	<li>the plan should use only those bamboo breeds whose lifetimes are m years or longer, and</li>
	<li>Dr. ACM should sow the seeds in all the blocks only this year.</li>
</ul>

### 입력 

 <p>The input consists of at most 50 datasets, each in the following format.</p>

<pre>m n</pre>

<p>An integer m (2 ≤ m ≤ 100) represents the lifetime (in years) of the bamboos with the shortest lifetime that Dr. ACM can use for gardening. An integer n (1 ≤ n ≤ 500,000) represents the number of blocks.</p>

<p>The end of the input is indicated by a line containing two zeros.</p>

### 출력 

 <p>No matter how good your plan is, a "dull-year" would eventually come, in which the bamboos do not flower in any block. For each dataset, output in a line an integer meaning how many years from now the first dull-year comes after the first m years.</p>

<p>Note that the input of m = 2 and n = 500,000 (the last dataset of the Sample Input) gives the largest answer.</p>

