{--------------------------------------------------------------------

---------------------------------------------------------------------}

import EulerLib qualified as E

main = do
  let eulerProblem = 16
      solution = (sum . E.toDigits) (2 ^ 1000)
  E.printProblemSolution eulerProblem solution
