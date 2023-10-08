{--------------------------------------------------------------------
<p>A Pythagorean triplet is a set of three natural numbers, $a \lt b \lt c$, for which,
\$$a^2 + b^2 = c^2.$$</p>
<p>For example, $3^2 + 4^2 = 9 + 16 = 25 = 5^2$.</p>
<p>There exists exactly one Pythagorean triplet for which $a + b + c = 1000$.<br>Find the product $abc$.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

uplist2 a aMax = map (\x -> (a, x)) [a + 1 .. aMax]

uplist3 (a, b) aMax = map (\x -> (a, b, x)) [b + 1 .. aMax]

main = do
  -- Idea: form a tuple list (a, b, c) for all possible combinations,
  -- then filter by valid combinations (a^2 + b^2 = c^2)
  -- then filter by a+b+c = 1000
  let eulerProblem = 9
  let maxNr = 1000
  let prod2list = foldr (\x a -> uplist2 x (maxNr - 1) ++ a) [] [2 .. maxNr - 2]
  let prod3list = foldr (\x a -> uplist3 x maxNr ++ a) [] prod2list
  let validProds = filter (\(a, b, c) -> a * a + b * b == c * c && a + b + c == 1000) prod3list
  let solution = head $ map (\(a, b, c) -> a * b * c) validProds
  E.printProblemSolution eulerProblem (show solution ++ " for the tuple " ++ show (head validProds))
