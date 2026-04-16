# [Platinum V] Rubik’s Cube Solver - 9972 

[문제 링크](https://www.acmicpc.net/problem/9972) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>The Rubik’s Cube was invented by Enro Rubik in 1974. It is a 3-dimensional puzzle made up of 26 smaller cubes. Each smaller cube has from one to three sides exposed for a total of 54 exposed sides. Each of these sides is assigned one of six colors, and each color is assigned to precisely nine exposed sides. The cube is manipulated by rotating any side of the cube by 90 degrees. It is considered solved when each side of the Rubik’s Cube is entirely covered by one of the six colors.</p>

<p>You are a researcher at the Rubik’s University and are working on an algorithm to solve a Rubik’s Cube in the least possible number of moves from any starting position. To aid in your research, you need a program that will read in various Rubik’s Cube configurations, perform operations on those configurations, and determine if the resulting cube is solved.</p>

### 입력 

 <p>Input to this problem will consist of a starting configuration for the Rubik’s Cube and then one or more operations to perform on the cube.</p>

<p>The input configuration will look like: </p>

<pre>      G W O
      G R R
      G B R
B R B R G Y W W W Y G O
G W B O G B Y B O W Y O
W R Y O Y B R Y R G O O
      B R Y
      B O W
      G Y W</pre>

<p>Which follows this layout:</p>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/9972/1.png" style="height:161px; width:212px"></p>

<p>Each character in this grid represents the color of the piece of the cube. There is one space between each character in the grid and possibly many spaces before the first character on a line. The grid represents the cube as is if it were unfolded and flattened out. Each group of 9 characters (3 x 3 array) represents one side of the grid. The top of the cube is represented by the first 3 lines of input. The next 3 lines of input represent the left, front, right, and back sides in that order. The last 3 lines represent the bottom of the cube.</p>

<p>Following the initial configuration will be 1 more operations to perform on the cube. There are 12 possible operations that can be performed, each being a 90 degree rotation of one of the cube’s ‘faces’ of 9 smaller cubes. Note that this results in the movement of 20 colored squares (8 on the face being rotated and 12 on the sides of the smaller cubes that make up that face). All 12 possible operations are listed in the table below with a description of how to perform that operation.</p>

<p>Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be no blank lines separating data sets.</p>

<p>There will be one or more data sets. A single data set has 2 components:</p>

<ol>
	<li>Start line - A single line, “START”.</li>
	<li>An initial configuration of the cube (9 lines total)</li>
	<li>One or more operations each on a separate line</li>
	<li>End line – A single line, “END”.</li>
</ol>

<p>Following the final data set will be a single line, “ENDOFINPUT”.</p>

<table class="table table-bordered">
	<thead>
		<tr>
			<th>Operation</th>
			<th>Description</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>front left</th>
			<td>Performed by rotating the front side counter-clockwise when viewing from the front</td>
		</tr>
		<tr>
			<th>front right</th>
			<td>Performed by rotating the front side clockwise when viewing from the front</td>
		</tr>
		<tr>
			<th>left left</th>
			<td>Performed by rotating the left side counter-clockwise when viewing from the left</td>
		</tr>
		<tr>
			<th>left right</th>
			<td>Performed by rotating the left side clockwise when viewing from the left</td>
		</tr>
		<tr>
			<th>right left</th>
			<td>Performed by rotating the right side counter-clockwise when viewing from the right</td>
		</tr>
		<tr>
			<th>right right</th>
			<td>Performed by rotating the right side clockwise when viewing from the right</td>
		</tr>
		<tr>
			<th>back left</th>
			<td>Performed by rotating the back side counter-clockwise when viewing from the back</td>
		</tr>
		<tr>
			<th>back right</th>
			<td>Performed by rotating the back side clockwise when viewing from the back</td>
		</tr>
		<tr>
			<th>top left</th>
			<td>Performed by rotating the top side counter-clockwise when viewing from the top</td>
		</tr>
		<tr>
			<th>top right</th>
			<td>Performed by rotating the top side clockwise when viewing from the top</td>
		</tr>
		<tr>
			<th>bottom left</th>
			<td>Performed by rotating the bottom side counter-clockwise when viewing from the bottom</td>
		</tr>
		<tr>
			<th>bottom right</th>
			<td>Performed by rotating the bottom side clockwise when viewing from the bottom</td>
		</tr>
	</tbody>
</table>

### 출력 

 <p>For each data set, there will be exactly one line of output. If the cube is solved, then the word “Yes” is output on a line. If the cube remains unsolved, then the word “No” is output on a line.</p>

