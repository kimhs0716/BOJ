# [Gold V] Card Counting Club - 31662 

[문제 링크](https://www.acmicpc.net/problem/31662) 

### 성능 요약

메모리: 11508 KB, 시간: 936 ms

### 분류

자료 구조, 구현, 우선순위 큐, 시뮬레이션

### 제출 일자

2025년 11월 26일 14:23:49

### 문제 설명

<p>During the creation of the Card Counting Club, the club wanted to combine their card counting practice along with the process of choosing player order for their games. They converged on a counting-out game that is played like so:</p>

<ol>
	<li>
	<p>At the beginning of the game, each player is dealt a hand with the same number of cards as everyone else.</p>
	</li>
	<li>
	<p>Each player begins the turn by showing the card with the smallest value in their hand to the other players.</p>
	</li>
	<li>
	<p>The player with the smallest card gets to discard it.</p>

	<ol>
		<li>
		<p>Only one player gets to discard their card, and the ties are broken by choosing the player’s whose name comes first lexicographically (i.e. standard dictionary order).</p>
		</li>
		<li>
		<p>All players that do not get to discard their card leave a small mark on their card and place it back into their hand. Each mark increases the value of the card by an agreed penalty amount.</p>
		</li>
	</ol>
	</li>
	<li>
	<p>When a player runs out of cards, they are counted out.</p>
	</li>
	<li>
	<p>The game is played until all players are counted out.</p>
	</li>
</ol>

<p>Once the game is over, the order of players as they were counted out is used to choose the order in which the club members get to play other games.</p>

<p>Over time, the club grew to 35 people, and the cost of the cards along with the time it takes to play out the game became too much. So, the club turns to you to make a program that will play out the game for them to save both time and the cost of the playing cards.</p>

### 입력 

 <p>The first line contains three integers $N, M, P$ $( 2 \leq N \leq 35$, $1 \leq M \leq 17\, 000$, and $1 \leq P \leq 10$) where $N$ is the number of players, $M$ is the hand size of each player, and $P$ is the penalty amount for each mark. The next $N$ lines contain the name of the player followed by $M$ space-separated integers $x_1, x_2, \ldots , x_ N$ ($1 \leq x_ i \leq 200\, 000$ for each $1 \leq i \leq M$) representing the values of the cards in the player’s hand. The values may repeat both within and between hands. Each player’s name will consist only of uppercase letters and will have length between $2$ and $10$.</p>

### 출력 

 <p>On a single line, display the list of player names in the order in which they are counted out in regular play of the game. Consecutive names on this line should be separated with a single space.</p>

