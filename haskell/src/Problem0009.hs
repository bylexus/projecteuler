module Problem0009 (solution) where

{--------------------------------------------------------------------
<p>A Pythagorean triplet is a set of three natural numbers, $a \lt b \lt c$, for which,
\$$a^2 + b^2 = c^2.$$</p>
<p>For example, $3^2 + 4^2 = 9 + 16 = 25 = 5^2$.</p>
<p>There exists exactly one Pythagorean triplet for which $a + b + c = 1000$.<br>Find the product $abc$.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

-- Idea: form a tuple list (a, b, c) for all possible combinations,
-- then filter by valid combinations (a^2 + b^2 = c^2)
-- then filter by a+b+c = 1000
solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 9,
      E.psTitle = "Special Pythagorean Triplet",
      E.psSolve = \_ -> show output,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

-- Build cartesian product of a,b,c, for each number a < b < c:
-- using a list comprehension:
maxNr :: Int
maxNr = 1000

abc :: [(Int, Int, Int)]
abc = [(a, b, c) | a <- [2 .. maxNr - 2], b <- [a + 1 .. maxNr - 1], c <- [b + 1 .. maxNr]]

validProds :: [(Int, Int, Int)]
validProds = filter (\(a, b, c) -> a * a + b * b == c * c && a + b + c == 1000) abc

sol :: Int
sol = head $ map (\(a, b, c) -> a * b * c) validProds

output :: String
output = show sol ++ " for the tuple " ++ show (head validProds)
