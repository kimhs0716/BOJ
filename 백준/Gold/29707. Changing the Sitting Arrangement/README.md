# [Gold III] Changing the Sitting Arrangement - 29707 

[문제 링크](https://www.acmicpc.net/problem/29707) 

### 성능 요약

메모리: 2156 KB, 시간: 4 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2025년 12월 19일 00:00:29

### 문제 설명

<p>You are the teacher of a class of <i>n</i><sup>2</sup> pupils at an elementary school. Seats in the classroom are set up in a square shape of <i>n</i> rows (row 1 through row <i>n</i>) by <i>n</i> columns (column 1 through column <i>n</i>).</p>

<p>You are planning a change in the sitting arrangement. In order for your pupils to interact with many different pupils, you want to make those currently on adjacent seats have remote seats.</p>

<p>There is at least one sitting arrangement such that every pair of pupils currently on adjacent seats have seats with the Manhattan distance of no less than ⌊<i>n</i> / 2⌋ between them. Your task is to find such an arrangement. Here, ⌊<i>x</i>⌋ represents the largest integer less than or equal to <i>x.</i> The Manhattan distance of two seats are the sum of the absolute difference of their row numbers and that of their column numbers. Adjacent seats mean those with the Manhattan distance 1.</p>

<p>For example, in the first dataset of Sample Input (<i>n</i> = 4), pupils at the four adjacent seats of the pupil no. 10 are those numbered 6, 9, 11, and 14. In the Output for the Sample Input corresponding to this, their seats have Manhattan distances 3, 3, 2, and 3 from the seat of the pupil no. 10, all of which are ⌊ 4 / 2 ⌋ = 2 or greater. This condition also holds for all the other pupils.</p>

### 입력 

 <p>The input consists of multiple datasets, each in the format below. The number of datasets does not exceed 50.</p>

<blockquote>
<p><i>n</i></p>

<p><i>a</i><sub>11</sub> <i>a</i><sub>12</sub> ⋯ <i>a</i><sub>1<i>n</i></sub></p>

<p><i>a</i><sub>21</sub> <i>a</i><sub>22</sub> ⋯ <i>a</i><sub>2<i>n</i></sub></p>

<p> ⋮</p>

<p><i>a</i><sub><i>n</i>1</sub> <i>a</i><sub><i>n</i>2</sub> ⋯ <i>a</i><sub><i>n</i><i>n</i></sub></p>
</blockquote>

<p>Here, <i>n</i> is the number of rows and also columns of the seats in the classroom (2 ≤ <i>n</i> ≤ 50). The following <i>n</i> lines denote the current sitting arrangement. Each <i>a</i><sub><i>ij</i></sub> gives the ID number of the pupil currently sitting in the <i>i</i>-th row from the back and the <i>j</i>-th column from the left, as seen from the teacher's desk. <i>a</i><sub><i>ij</i></sub>'s are integers 1 through <i>n</i><sup>2</sup>, without duplicates.</p>

<p>The end of the input is indicated by a line consisting of a single zero.</p>

### 출력 

 <p>For each dataset, output a sitting arrangement satisfying the condition stated above in the same format as in the input. If there are two or more such arrangements, any of them will do.</p>

