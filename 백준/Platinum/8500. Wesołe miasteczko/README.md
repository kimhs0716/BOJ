# [Platinum V] Wesołe miasteczko - 8500 

[문제 링크](https://www.acmicpc.net/problem/8500) 

### 성능 요약

메모리: 2536 KB, 시간: 560 ms

### 분류

다이나믹 프로그래밍, 최장 공통 부분 수열 문제

### 제출 일자

2026년 4월 9일 00:39:46

### 문제 설명

<p>Bajtazar i Bajtoni wybrali się do wesołego miasteczka. Odwiedzali to miejsce już wiele razy i dobrze znają wszystkie atrakcje, dlatego każdy z nich przygotował zawczasu listę swoich ulubionych atrakcji, które chciałby po kolei odwiedzić. Listy różniły się od siebie, dlatego przyjaciele zdecydowali się wykreślić z nich niektóre pozycje, tak, by stały się one identyczne. Nie chcą przy tym zmieniać oryginalnej kolejności z każdej z list. Dodatkowo, chcieliby, aby uzgodniony plan był najdłuższy możliwy. Ile różnych planów mogą w ten sposób uzyskać?</p>

### 입력 

 <p>W pierwszym wierszu wejścia znajdują się dwie liczby całkowite n1 i n2 (1 ≤ n1,n2 ≤ 10000), oznaczające długości planów Bajtazara i Bajtoniego. Kolejne dwa wiersze zawierają listy atrakcji zaproponowane przez każdego z nich. Są to listy liczb całkowitych z przedziału [1,10000] pooddzielanych pojedynczymi odstępami, długości odpowiednio n1 i n2. Każda liczba określa jedną atrakcję w wesołym miasteczku.</p>

### 출력 

 <p>W pierwszym i jedynym wierszu standardowego wyjścia wypisz jedną liczbę całkowitą. Powinna to być liczba różnych planów zwiedzania wesołego miasteczka, które mogą utworzyć przyjaciele poprzez wykreślanie pozycji z zaproponowanych przez siebie list atrakcji modulo 1000000007.</p>

