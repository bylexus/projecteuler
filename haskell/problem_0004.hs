{--------------------------------------------------------------------
<p>A palindromic number reads the same both ways. The largest palindrome made from the product of two $2$-digit numbers is $9009 = 91 \times 99$.</p>
<p>Find the largest palindrome made from the product of two $3$-digit numbers.</p>
---------------------------------------------------------------------}
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
