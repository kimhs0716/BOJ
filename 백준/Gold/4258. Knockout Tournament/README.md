# [Gold III] Knockout Tournament - 4258 

[문제 링크](https://www.acmicpc.net/problem/4258) 

### 성능 요약

메모리: 108384 KB, 시간: 84 ms

### 분류

수학

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>In a knockout tournament there are 2<sup>n</sup> players. One loss and a player is out of the tournament. Winners then play each other with the new winners advancing until there is only one winner left. If we number the players 1, 2, 3,..., 2<sup>n</sup>, with the first round pairings 2k−1 vs 2k, for k = 1, 2,..., 2<sup>n−1</sup>, then we could give the results of the tournament in a complete binary tree. The winners are indicated in the interior nodes of the tree. Below is an example of a tournament with n = 3.</p>

<p><img alt="" src="" style="height:142px; width:267px"></p>

<p>After the tournament, some reporters were arguing about the relative ranking of the players, as determined by the tournament results. It’s assumed that if player A beats player B who in turn beats player C, that player A will also beat player C; that is, winning is transitive. Now there is no doubt who the best player is. The question is what is the highest ranking a player can reasonably claim as a result of the tournament and what is the worst ranking a player can have, as a result of the tournament? For example, in the above tournament player 2, having lost to the eventual winner, could claim to be the 2nd best player in the field, but could well be the worst (ranked 8th). Player 5 could claim to be as high as 3rd (having lost to someone who could be 2nd) but no worse than 7th (having beaten one player in the 1st round).</p>

<p>You are to determine the highest and lowest possible rankings of a set of players in the field, given the results of the tournament.</p>

### 입력 

 <p>There will be multiple input instances. The input for each instance consists of three lines. The first line will contain a positive integer n < 8, indicating there are 2<sup>n</sup> players in the tournament, numbered 1 through 2<sup>n</sup>, paired in the manner indicated above. A value of n = 0 indicates end of input. The next line will contain the results of each round of the tournament (listed left-to-right) starting with the 1st round. For example, the tournament above would be given by</p>

<pre>1 3 5 8 1 8 1</pre>

<p>The final line of input for each instance will be a positive integer m followed by integers k<sub>1</sub>, ..., k<sub>m</sub>, where each k<sub>i</sub> is a player in the field.</p>

### 출력 

 <p>For each k<sub>i</sub>, issue one line of output of the form:</p>

<pre>Player k<sub>i</sub> can be ranked as high as h or as low as l.</pre>

<p>where you supply the appropriate numbers. These lines should appear in the same order as the k<sub>i</sub> did in the input. Output for problem instances should be separated with a blank line.</p>

