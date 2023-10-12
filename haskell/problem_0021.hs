{--------------------------------------------------------------------
<p>Let $d(n)$ be defined as the sum of proper divisors of $n$ (numbers less than $n$ which divide evenly into $n$).<br>
If $d(a) = b$ and $d(b) = a$, where $a \ne b$, then $a$ and $b$ are an amicable pair and each of $a$ and $b$ are called amicable numbers.</p>
<p>For example, the proper divisors of $220$ are $1, 2, 4, 5, 10, 11, 20, 22, 44, 55$ and $110$; therefore $d(220) = 284$. The proper divisors of $284$ are $1, 2, 4, 71$ and $142$; so $d(284) = 220$.</p>
<p>Evaluate the sum of all the amicable numbers under $10000$.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

main = do
  let eulerProblem = 21
      numbers = [1 .. 9999]
      divsumPairs = map (\x -> (x, sum (E.divisors x))) numbers
      amicableNumbers = [a | (a, b) <- divsumPairs, (c, d) <- divsumPairs, a /= b && a == d && b == c]
      solution = sum amicableNumbers
  E.printProblemSolution eulerProblem solution
