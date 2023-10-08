{--------------------------------------------------------------------
<p>A Pythagorean triplet is a set of three natural numbers, $a \lt b \lt c$, for which,
\$$a^2 + b^2 = c^2.$$</p>
<p>For example, $3^2 + 4^2 = 9 + 16 = 25 = 5^2$.</p>
<p>There exists exactly one Pythagorean triplet for which $a + b + c = 1000$.<br>Find the product $abc$.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

main = do
  -- Idea: form a tuple list (a, b, c) for all possible combinations,
  -- then filter by valid combinations (a^2 + b^2 = c^2)
  -- then filter by a+b+c = 1000
  let eulerProblem = 9
  let maxNr = 1000
  -- Build cartesian product of a,b,c, for each number a < b < c:
  -- using a list comprehension:
  let abc = [(a, b, c) | a <- [2 .. maxNr - 2], b <- [a + 1 .. maxNr - 1], c <- [b + 1 .. maxNr]]
  let validProds = filter (\(a, b, c) -> a * a + b * b == c * c && a + b + c == 1000) abc

  let solution = head $ map (\(a, b, c) -> a * b * c) validProds
  E.printProblemSolution eulerProblem (show solution ++ " for the tuple " ++ show (head validProds))
