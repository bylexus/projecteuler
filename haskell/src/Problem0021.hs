module Problem0021 (solution) where

{--------------------------------------------------------------------
<p>Let $d(n)$ be defined as the sum of proper divisors of $n$ (numbers less than $n$ which divide evenly into $n$).<br>
If $d(a) = b$ and $d(b) = a$, where $a \ne b$, then $a$ and $b$ are an amicable pair and each of $a$ and $b$ are called amicable numbers.</p>
<p>For example, the proper divisors of $220$ are $1, 2, 4, 5, 10, 11, 20, 22, 44, 55$ and $110$; therefore $d(220) = 284$. The proper divisors of $284$ are $1, 2, 4, 71$ and $142$; so $d(284) = 220$.</p>
<p>Evaluate the sum of all the amicable numbers under $10000$.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 21,
      E.psTitle = "Amicable Numbers",
      E.psSolve = \_ -> show solutionNr,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

numbers :: [Int]
numbers = [1 .. 9999]

divsumPairs :: [(Int, Int)]
divsumPairs = map (\x -> (x, sum (E.divisors x))) numbers

amicableNumbers :: [Int]
amicableNumbers = [a | (a, b) <- divsumPairs, (c, d) <- divsumPairs, a /= b && a == d && b == c]

solutionNr :: Int
solutionNr = sum amicableNumbers
