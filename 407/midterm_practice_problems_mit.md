# Exam 1 Practice Questions I, 18.05, Spring 2014

*Taken from: [mit-ocw 18.05](https://ocw.mit.edu/courses/mathematics/18-05-introduction-to-probability-and-statistics-spring-2014/exams/MIT18_05S14_Prac_Exam1a.pdf)*

1. PROBABILITY has 11 letters, with 2 B's and 2 I's, so: 

$$\boxed{\frac{11!}{2!2!}}$$

2. There are $\binom{6}{4} = 15$ ways to pick 4 men and $\binom{7}{4} = 35$ ways to pick 4 women. Then there are $4!$ ways to arrange the pairs, so that makes $15(35)(24) = \boxed{12600}$ pairs.

3. It's just the complement, so $$\boxed{\frac 1 3}$$

4. We have $P(C \cap D) + P(C^c \cap D) = P(D)$. So $0.45 - 0.1 = \boxed{0.35}$.

5. Probability of choosing the right answer is $p + (1- p) / c$. So $$\boxed{\frac{p}{p + (1-p)/c}}$$

6.
    a. Given that $C$ occurs, the other die must be 2, so $\boxed{1/6}$.

    b. Given that $C$ occurs, the other die must be 6, so also $\boxed{1/6}$.

    c. No, $A$ and $C$ are not independent. Same for $B$ and $C$.

7. The probability of getting the correct answer is $0.5 + 0.25(1/3) + 0.25(0.25) = 24/48 + 4/48 + 3/48 = 31/48$. So $$\frac{1/2}{31/48} = \boxed{\frac{24}{31}}$$

8. $P(A \cup B) = 1 - 0.42 = 0.58$ and $P(A \cap B) = P(A) + P(B) - P(A\cup B) = 0.4 + 0.3 - 0.58 = 0.12 = P(A)P(B)$. So yes, they are indenpendent.

9. The expected value is $$\int_0^1x (2x) dx = \frac 2 3,$$ and $\mathbb E(X^2)$ is $$\int_0^1 x^2(2x) dx = \frac 1 2.$$ So $\text{Var}(X) = \mathbb E(X^2) - \mathbb E (X)^2 = 1/2 - 4/9 = \boxed{1/18}$.

Next, $\mathbb E (X^4)$ is $$\int_0^1 x^4 (2x) dx = \frac 1 3,$$ so $\text{Var}(X^2) = \mathbb E (X^4) = \mathbb E(X^2)^2 = 1/3 - 1/4 = \boxed{1/12}$.

10. 