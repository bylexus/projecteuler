{--------------------------------------------------------------------
<p>By listing the first six prime numbers: $2, 3, 5, 7, 11$, and $13$, we can see that the $6$th prime is $13$.</p>
<p>What is the $10\,001$st prime number?</p>
---------------------------------------------------------------------}
import EulerLib qualified as E

main =
  let eulerProblem = 7
      solution = last $ take 10001 E.primeList
   in E.printProblemSolution eulerProblem solution
