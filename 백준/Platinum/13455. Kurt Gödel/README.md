# [Platinum III] Kurt Gödel - 13455 

[문제 링크](https://www.acmicpc.net/problem/13455) 

### 성능 요약

메모리: 70364 KB, 시간: 8288 ms

### 분류

수학, 자료 구조, 정수론, 집합과 맵, 모듈로 곱셈 역원, 중간에서 만나기

### 제출 일자

2025년 7월 15일 16:02:23

### 문제 설명

<p>Kurt Friedrich Gödel was an Austrian mathematician and philosopher. He was influenced by previous scientist philosophers such as Isaac Newton and Immanuel Kant. And then later he also influenced mathematicians and philosophers such as Bertrand Russell. He utilized something known as the Gödel numbering in the proof of his famous “Incompleteness theorem”, a theorem that tests the boundary and limit of mathematics and logic itself. This makes him one of the most important logician in the history among the likes of Aristotle.</p>

<p>Let’s see how this Gödel numbering system works. It assigns a number to each symbol, in this case we use capital alphabets (A to Z) and assign them to natural numbers 1 to 26. So that A is assigned to 1, B is assigned to 2 and so on. So a word such as KURT will become a sequence (11, 21, 18, 20). Then, we represent it as product of prime powers. A sequence (a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub>) should be encoded into 2<sup>a1</sup> · 3<sup>a2</sup> · · · · · p<sup>a+n</sup><sub>n</sub> where p<sub>i</sub> is the i-th prime number. I.e., the Gödel number of KURT is 2<sup>11</sup> · 3<sup>21</sup> · 5<sup>18</sup>· 7<sup>20</sup> = 6520744440162926921184290648437500000000000.</p>

<p>The Gödel number of a long word might be very large. Your friend Albert would like to leave a message for you by using Gödel numbers, but he is lazy to write all the digits. Albert uses a triple (ℓ, r, p) to represent a Gödel number g where ℓ is the length of the corresponding word, p is a prime, and r ≡ g(mod p). However, Albert doesn’t notice that two words can generate the same triple. For instance, the Gödel numbers EA and JA are 96 and 3072 respectively, but Albert may use (2, 3, 31) to represent both of them. Let’s try to decode Albert’s message!</p>

### 입력 

 <p>There will be at most 30 test cases. Each test case will be given on a line containing three integers. The first integer ℓ (1 ≤ ℓ ≤ 8) is the length of this word. The second integer r represents the remainder of the result. The third integer is the prime number p used in modulo operation. We guarantee that 0 ≤ r < p < 2<sup>31</sup>. The input will be terminated with three zeros on a line.</p>

### 출력 

 <p>Output the word that generates this triple if it is unique. Output “ambiguous” if more than one possibility exists. Output “not a word” if there exists no word that can produce this triple.</p>

