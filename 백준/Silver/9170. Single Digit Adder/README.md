# [Silver III] Single Digit Adder - 9170 

[문제 링크](https://www.acmicpc.net/problem/9170) 

### 성능 요약

메모리: 30860 KB, 시간: 64 ms

### 분류

구현

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Write a program that can evaluate expressions from the following roughly BNF (Backus Naur Form) grammar:</p>

<pre>expr ::=  term | expr ‘+’ term | expr ‘-’ term
unary_op ::= ‘+’ term | ‘-’ term
term ::= ‘(’ expr ‘)’ | ‘(’ unary_op ‘)’ | literal
literal ::= [0-9]</pre>

<p>There will be no whitespace within an expression. All expressions will consist solely of the characters (, ), +, -, and the digits 0 through 9. You may assume that all input is well-formed.</p>

### 입력 

 <p>The input will consist of one expression per line followed by a newline. The length of expression does not exceed 200.</p>

<p>There will be no blank lines in the file.</p>

### 출력 

 <p>For each expression, output its integer value, followed by a single newline.</p>

