# [Platinum V] Sure Bet - 15247 

[문제 링크](https://www.acmicpc.net/problem/15247) 

### 성능 요약

메모리: 118056 KB, 시간: 188 ms

### 분류

이분 탐색, 그리디 알고리즘, 정렬, 두 포인터

### 제출 일자

2026년 1월 7일 01:12:32

### 문제 설명

<p>Luck is a fundamental part of betting. Some people improve their chances and earnings by having good knowledge of what they are betting on. We will take a different approach.</p>

<p>Various bookmakers offer different odds or quotas for the same outcome. (An odds of x means that if you bet 1 euro and predict the outcome correctly, you get x euros back. If you predict the outcome incorrectly, you of course get nothing back. Note that you pay 1 euro regardless of the outcome.) What if you could be certain of making a profit by cleverly placing several bets? You would want to make this guaranteed profit as large as possible.</p>

<p>The event we want to bet on has two possible outcomes. There are n bookmakers that offer different odds. Let us denote the odds offered by the i-th bookmaker for the first outcome with a<sub>i</sub>, and the odds offered for the second outcome with b<sub>i</sub>. You can place a bet on any subset of the offered odds. You can even bet on both outcomes at the same bookmaker. However, all bets have to be exactly 1 euro and you cannot bet on the same outcome with the same bookmaker multiple times.</p>

<p>In case of the first outcome, you will receive a<sub>i</sub> euros from every bookmaker i with whom you placed a bet on the first outcome. Similarly, in case of the second outcome, you will receive b<sub>i</sub> euros from all eligible bookmakers. Of course in both cases, you already paid 1 euro for every bet you placed.</p>

<p>What is the largest guaranteed profit (i.e. regardless of the outcome) if you place your bets optimally?</p>

### 입력 

 <p>The first line contains the number of bookmakers, n. The following n lines describe the odds offered by each bookmaker with two space-separated real numbers a<sub>i</sub> and b<sub>i</sub> - the odds for the first and second outcome offered by the i-th bookmaker. The odds will be given to at most 4 decimal places.</p>

### 출력 

 <p>Output the maximum guaranteed profit rounded to exactly 4 decimal places.</p>

<p>Here are the commands to print the floating point numbers in various languages:</p>

<ul>
	<li>C and C++: <code>printf("%.4lf",(double)x);</code></li>
	<li>Java: <code>System.out.printf("%.4lf",x);</code></li>
	<li>Pascal: <code>writeln(x:0:4);</code></li>
	<li>Python 3: <code>print("%.4lf"%x)</code></li>
	<li>C#: <code>Console.WriteLine(String.Format("0:0.0000",x));</code></li>
</ul>

