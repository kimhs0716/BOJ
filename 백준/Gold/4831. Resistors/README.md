# [Gold III] Resistors - 4831 

[문제 링크](https://www.acmicpc.net/problem/4831) 

### 성능 요약

메모리: 128744 KB, 시간: 320 ms

### 분류

구현, 자료 구조, 문자열, 파싱, 스택, 물리학

### 제출 일자

2026년 2월 28일 19:41:51

### 문제 설명

<p>Every electrical appliance (such as a light bulb) has a certain resistance. If the appliance is connected to a given voltage, the higher its resistance, the lower the current flowing through the appliance. The unit of measurement for resistance is the ohm. In order to avoid round-off errors that can affect floating-point numbers, we will use rational numbers (quotients of positive integers) to represent the resistance of an appliance numerically.</p>

<p>There are two basic ways to connect two or more appliances into a configuration of appliances: serially (Figure 1) or parallel (Figure 2).</p>

<p>Two or more configurations can be further connected serially or parallel to yield another (more complex) configuration yet, and this process of building more complex configurations from existing ones can be repeated any number of times (Figure 3).</p>

<p>In general, a configuration is either a single appliance, or a serial connection of two or more configurations, or a parallel connection of two or more configurations.</p>

<p>The resistance of a configuration of resistors can be computed according to the following two rules:</p>

<ol>
	<li>The resistance of a serial configuration is the sum of the resistances of its component configurations.</li>
	<li>The resistance of a parallel configuration is the reciprocal of the sum of the reciprocals of its component configurations.</li>
</ol>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/resi1.png" style="height:246px; width:598px"></p>

<p>In Figure 1, the resistance of the configuration is 3/2 + 3/4 + 1/4 = 5/2 ohm.</p>

<p>In Figure 2, the resistance of the configuration is 1/(1/(3/2) + 1/(1/2) + 1/ (1/4)) = 3/20 ohm</p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/resi2.png" style="height:213px; width:534px"></p>

<p>In Figure 3, we first calculate 1/(1/(1/2) + 1/(2/3)) + 2/5 = 24/35 and 1/2 + 1/(1/(2/3) + 1/(2/5)) + 3/2 = 9/4. Adding the reciprocals of these two values and reciprocating the result, we get 72/137 ohm.</p>

<p>A configuration can be represented in text format.</p>

<ul>
	<li>A single appliance is represented by the numerical value of its resistance (without enclosing parentheses).</li>
	<li>A configuration that is the serial connection of several configurations is represented as a list of the representations of its components, separated by the ampersand character ("&") and enclosed in a pair of parentheses.</li>
	<li>A configuration that is the parallel connection of several configurations is represented as a list of the representations of its components, separated by the vertical bar character ("|") and enclosed in a pair of parentheses.</li>
</ul>

<p>Thus, figures 1, 2, and 3 are represented in text format by the respective expressions:</p>

<pre>(3/2 & 3/4 & 1/4)
(3/2 | 1/2 | 1/4)
(((1/2 | 2/3) & 2/5) | (1/2 & (2/3 | 2/5) & 3/2))</pre>

### 입력 

 <p>The input consists of a number of test cases, one test case per line. Each line of the input contains a valid expression that defines a configuration according to the rules stated above. The resistance values of the appliances will be positive rational numbers, in the form NUMERATOR/DENOMINATOR. There will be one blank space on each side of every ampersand or vertical bar. There will be no other blank spaces in the expression.</p>

### 출력 

 <p>For each test case, print the resistance of the configuration on a new line, in the form NUMERATOR/DENOMINATOR, with all common factors of NUMERATOR and DENOMINATOR cancelled. Do not print any blank spaces.</p>

