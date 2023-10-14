module Problem0004 (solution) where

{--------------------------------------------------------------------
<p>A palindromic number reads the same both ways. The largest palindrome made from the product of two $2$-digit numbers is $9009 = 91 \times 99$.</p>
<p>Find the largest palindrome made from the product of two $3$-digit numbers.</p>
---------------------------------------------------------------------}
import EulerLib qualified as E

solution =
  E.ProblemSolution
    { E.psNr = 4,
      E.psTitle = "Largest Palindrome Product",
      E.psSolve = \_ -> show (E.listMax $ filter isPalindrom $ E.cross (*) input input),
      E.psSolution = "",
      E.psReadInput = pure ""
    }

input = [100 .. 999]

isPalindrom :: Integer -> Bool
isPalindrom i = digits == reverse digits
  where
    digits = E.toDigits i
