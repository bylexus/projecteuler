{--------------------------------------------------------------------
<p>Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.</p>
(see data_0013.txt)
---------------------------------------------------------------------}

import EulerLib qualified as E

main = do
  input <- readFile "data_0013.txt"

  let eulerProblem = 13
      linesToInteger = map (\x -> read x ::Integer) . lines
      numbers =  linesToInteger input
      sumStr = show $ sum numbers
      solution = take 10 sumStr
  E.printProblemSolution eulerProblem solution
