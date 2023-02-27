# [Silver IV] 국기 인식 - 3100 

[문제 링크](https://www.acmicpc.net/problem/3100) 

### 성능 요약

메모리: 2024 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘(bruteforcing), 구현(implementation)

### 문제 설명

<p>Ante is developing a flag recognition system. After a series of filters and algorithms we get a 6×9 matrix of characters where same character denotes same color. </p>

<p>The system is in the initial phase of development, so Ante has set a goal to recognize simple flags like these:</p>

<pre>CCCCCCCCC     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ
CCCCCCCCC     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ
BBBBBBBBB     BBBBBBBBB     ZZZBBBCCC     ZZZAAAZZZ
BBBBBBBBB     BBBBBBBBB     ZZZBBBCCC     ZZZAAAZZZ
PPPPPPPPP     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ
PPPPPPPPP     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ</pre>

<p>In other words, simple flags that ante is considering consists of three equal stripes horizontally or vertically. The color on the middle stripe must differ from the colors on other two stripes. </p>

<p>For each matrix, we define a flag similarity measure as the minimum number of cells that need to be replaced by other characters for the matrix to become a simple flag. </p>

<p>Write a program that calculates a flag similarity measure for given matrix. </p>

### 입력 

 <p>Six lines contains nine upper case english letters each, the matrix. </p>

<p> </p>

### 출력 

 <p>Output one integer, flag similarity measure for given matrix. </p>

<p> </p>

