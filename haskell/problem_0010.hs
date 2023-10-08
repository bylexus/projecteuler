{--------------------------------------------------------------------
<p>The sum of the primes below $10$ is $2 + 3 + 5 + 7 = 17$.</p>
<p>Find the sum of all the primes below two million.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

main = do
  let eulerProblem = 10
  E.printProblemSolution eulerProblem solution
  where
    border = 2_000_000 :: Integer
    solution = (sum . takeWhile (< border)) E.primeList
