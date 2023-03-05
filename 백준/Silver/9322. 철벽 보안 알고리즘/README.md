# [Silver IV] 철벽 보안 알고리즘 - 9322 

[문제 링크](https://www.acmicpc.net/problem/9322) 

### 성능 요약

메모리: 2324 KB, 시간: 56 ms

### 분류

자료 구조(data_structures), 해시를 사용한 집합과 맵(hash_set), 문자열(string)

### 문제 설명

<p>Alice thinks it is very inconvenient to have to keep one of her keys in a public–private key pair secret. Therefore she invented a public–public key encryption scheme called the Really Secure Algorithm (RSA). The algorithm works as follows:</p>

<p>A <em>word</em> is a sequence of between one and ten capital letters (A–Z). A <em>sentence</em> is a sequence of words, separated by spaces. The <em>ﬁrst public key</em> is a sentence in which each word is used at most once. The <em>second public key</em> is a sentence formed by applying a permutation σ to the words in the ﬁrst public key. The <em>plaintext</em> (the unencrypted message) is a sentence that has exactly as many words as the public keys. (Unlike for the public keys, these words are not necessarily unique.) The <em>ciphertext</em> (the encrypted message) is the sentence formed by applying the permutation σ to the plaintext.</p>

<p>Given the two public keys and the ciphertext, recover the plaintext.</p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with an integer n (1 ≤ n ≤ 1 000): the number of words in each sentence.</li>
	<li>one line with a sentence: the ﬁrst public key.</li>
	<li>one line with a sentence: the second public key.</li>
	<li>one line with a sentence: the ciphertext.</li>
</ul>

<p>All words consist of at least 1 and at most 10 uppercase letters.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with a sentence: the plaintext.</li>
</ul>

