{--------------------------------------------------------------------
<p>$2^{15} = 32768$ and the sum of its digits is $3 + 2 + 7 + 6 + 8 = 26$.</p>
<p>What is the sum of the digits of the number $2^{1000}$?</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

main = do
  let eulerProblem = 16
      solution = (sum . E.toDigits) (2 ^ 1000)
  E.printProblemSolution eulerProblem solution
