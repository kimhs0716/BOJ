# [Gold I] Leonardo’s Notebook - 3706 

[문제 링크](https://www.acmicpc.net/problem/3706) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

순열 사이클 분할

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p><img alt="" src="" style="float:right; height:293px; width:260px">— I just bought Leonardo’s secret notebook!</p>

<p>Rare object collector Stan Ucker was really agitated but his friend, special investigator Sarah Keptic was unimpressed.</p>

<p>— How do you know it is genuine?</p>

<p>— Oh, it must be, at that price. And it is written in the da Vinci code.</p>

<p>Sarah browsed a few of the pages. It was obvious to her that the code was a substitution cipher, where each letter of the alphabet had been substituted by another letter.</p>

<p>— Leonardo would have written the plain-text and left it to his assistant to encrypt, she said. And he must have supplied the substitution alphabet to be used. If we are lucky, we can find it on the back cover!</p>

<p>She turned up the last page and, lo and behold, there was a single line of all 26 letters of the alphabet:</p>

<p>QWERTYUIOPASDFGHJKLZXCVBNM</p>

<p>— This may be Leonardo’s instructions meaning that each A in the plain-text was to be replaced by Q, each B with W, etcetera. Let us see...</p>

<p>To their disappointment, they soon saw that this could not be the substitution that was used in the book. Suddenly, Stan brightened.</p>

<p>— Maybe Leonardo really wrote the substitution alphabet on the last page, and by mistake his assistant coded that line as he had coded the rest of the book. So the line we have here is the result of applying some permutation TWICE to the ordinary alphabet!</p>

<p>Sarah took out her laptop computer and coded fiercely for a few minutes. Then she turned to Stan with a sympathetic expression.</p>

<p>— No, that couldn’t be it. I am afraid that you have been duped again, my friend. In all probability, the book is a fake.</p>

<p>Write a program that takes a permutation of the English alphabet as input and decides if it may be the result of performing some permutation twice.</p>

### 입력 

 <p>The input begins with a positive number on a line of its own telling the number of test cases (at most 500). Then for each test case there is one line containing a permutation of the 26 capital letters of the English alphabet.</p>

### 출력 

 <p>For each test case, output one line containing Yes if the given permutation can result from applying some permutation twice on the original alphabet string ABC...XYZ, otherwise output No.</p>

