import EulerLib


isPalindrom :: Integer -> Bool
isPalindrom i = digits == reverse digits
  where
    digits = toDigits i

main =
  let eulerProblem = 4
      input = [100 .. 999]
      solution = listMax $ filter isPalindrom $ cross (*) input input
   in EulerLib.printProblemSolution eulerProblem solution
