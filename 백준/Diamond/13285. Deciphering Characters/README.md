# [Diamond V] Deciphering Characters - 13285 

[문제 링크](https://www.acmicpc.net/problem/13285) 

### 성능 요약

메모리: 2448 KB, 시간: 36 ms

### 분류

트리, 트리 동형 사상

### 제출 일자

2026년 04월 17일 01:18:13

### 문제 설명

<p>Image data which are left by a mysterious syndicate were discovered. You are requested to analyze the data. The syndicate members used characters invented independently. A binary image corresponds to one character written in black ink on white paper.</p>

<p>Although you found many variant images that represent the same character, you discovered that you can judge whether or not two images represent the same character with the surrounding relation of connected components. We present some definitions as follows. Here, we assume that white pixels fill outside of the given image.</p>

<ul>
	<li>White connected component : A set of white pixels connected to each other horizontally or vertically (see below).</li>
	<li>Black connected component : A set of black pixels connected to each other horizontally, vertically, or diagonally (see below).</li>
	<li>Connected component : A white or a black connected component.</li>
	<li>Background component : The connected component including pixels outside of the image. Any white pixels on the periphery of the image are thus included in the background component.</li>
</ul>

<table class="table table-bordered">
	<tbody>
		<tr>
			<td style="text-align: center;"><img alt="" src="" style="height:79px; width:79px"></td>
			<td style="text-align: center;"><img alt="" src="" style="height:79px; width:79px"></td>
			<td style="text-align: center;"><img alt="" src="" style="height:79px; width:79px"></td>
			<td style="text-align: center;"><img alt="" src="" style="height:79px; width:79px"></td>
		</tr>
		<tr>
			<td style="text-align: center;">connected</td>
			<td style="text-align: center;">disconnected</td>
			<td style="text-align: center;">connected</td>
			<td style="text-align: center;">connected</td>
		</tr>
		<tr>
			<td colspan="2" style="text-align: center;">Connectedness of white pixels</td>
			<td colspan="2" style="text-align: center;">Connectedness of black pixels</td>
		</tr>
	</tbody>
</table>

<p>Let C<sub>1</sub> be a connected component in an image and C<sub>2</sub> be another connected component in the same image with the opposite color. Let's think of a modified image in which colors of all pixels not included in C<sub>1</sub> nor C<sub>2</sub> are changed to that of C<sub>2</sub>. If neither C<sub>1</sub> nor C<sub>2</sub> is the background component, the color of the background component is changed to that of C<sub>2</sub>. We say that C<sub>1</sub> surrounds C<sub>2</sub> in the original image when pixels in C<sub>2</sub> are not included in the background component in the modified image. (see below)</p>

<p style="text-align: center;"><img alt="" src="" style="height:182px; width:208px"></p>

<p>Two images represent the same character if both of the following conditions are satisfied.</p>

<ul>
	<li>The two images have the same number of connected components.</li>
	<li>Let S and S' be the sets of connected components of the two images. A bijective function f : S → S' satisfying the following conditions exists.
	<ul>
		<li>For each connected component C that belongs to S, f (C) has the same color as C.</li>
		<li>For each of C<sub>1</sub> and C<sub>2</sub> belonging to S, f (C<sub>1</sub>) surrounds f (C<sub>2</sub>) if and only if C<sub>1</sub> surrounds C<sub>2</sub>.</li>
	</ul>
	</li>
</ul>

<p>Let's see an example. Connected components in the images of the figure below has the following surrounding relations.</p>

<ul>
	<li>C<sub>1</sub> surrounds C<sub>2</sub>.</li>
	<li>C<sub>2</sub> surrounds C<sub>3</sub>.</li>
	<li>C<sub>2</sub> surrounds C<sub>4</sub>.</li>
	<li>C'<sub>1</sub> surrounds C'<sub>2</sub>.</li>
	<li>C'<sub>2</sub> surrounds C'<sub>3</sub>.</li>
	<li>C'<sub>2</sub> surrounds C'<sub>4</sub>.</li>
</ul>

<p>A bijective function defined as f (C<sub>i</sub>) = C'<sub>i</sub> for each connected component satisfies the conditions stated above. Therefore, we can conclude that the two images represent the same character.</p>

<p style="text-align: center;"><img alt="" src="" style="height:79px; width:156px"><img alt="" src="" style="height:208px; width:182px"></p>

<p>Make a program judging whether given two images represent the same character.</p>

<p> </p>

### 입력 

 <p>The input consists of at most 200 datasets. The end of the input is represented by a line containing two zeros. Each dataset is formatted as follows.</p>

<pre>image 1
image 2</pre>

<p>Each image has the following format.</p>

<pre>h w
p(1,1) ... p(1,w)
...
p(h,1) ... p(h,w)</pre>

<p>h and w are the height and the width of the image in numbers of pixels. You may assume that 1 ≤ h ≤ 100 and 1 ≤ w ≤ 100. Each of the following h lines consists of w characters. p(y,x) is a character representing the color of the pixel in the y-th row from the top and the x-th column from the left. Characters are either a period (".") meaning white or a sharp sign ("#") meaning black.</p>

### 출력 

 <p>For each dataset, output "yes" if the two images represent the same character, or output "no", otherwise, in a line. The output should not contain extra characters.</p>

