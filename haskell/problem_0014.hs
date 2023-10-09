{--------------------------------------------------------------------
<p>The following iterative sequence is defined for the set of positive integers:</p>
<ul style="list-style-type:none;">
<li>$n \to n/2$ ($n$ is even)</li>
<li>$n \to 3n + 1$ ($n$ is odd)</li></ul>
<p>Using the rule above and starting with $13$, we generate the following sequence:
\$$13 \to 40 \to 20 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1.$$</p>
<p>It can be seen that this sequence (starting at $13$ and finishing at $1$) contains $10$ terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at $1$.</p>
<p>Which starting number, under one million, produces the longest chain?</p>
<p class="note"><b>NOTE:</b> Once the chain starts the terms are allowed to go above one million.</p>
---------------------------------------------------------------------}

import Data.Map.Strict qualified as Map
import EulerLib qualified as E

type CollatzMap = Map.Map Int Int


nextCollatz :: Int -> Int
nextCollatz 1 = 1
nextCollatz n =
  if even n
    then n `div` 2
    else 3 * n + 1

collatzLength :: Int -> CollatzMap -> (Int, CollatzMap)
collatzLength 1 cMap = (1, cMap)
collatzLength n cMap = case Map.lookup n cMap of
  Just nr -> (nr, cMap)
  Nothing -> (cnt, finalMap)
  where
    nextNr = nextCollatz n
    (nextLen, newMap) = collatzLength nextNr cMap
    cnt = 1 + nextLen
    finalMap = Map.insert n cnt newMap

collatzLengthsForList :: [Int] -> CollatzMap -> ([(Int, Int)], CollatzMap)
collatzLengthsForList [] m = ([], m)
collatzLengthsForList (x : xs) m = ((x, ln) : rest, finalMap)
  where
    (ln, newMap) = collatzLength x m
    (rest, finalMap) = collatzLengthsForList xs newMap

findLongest :: [(Int, Int)] -> (Int, Int)
findLongest [] = (0, 0)
findLongest ((nr, l) : xs) =
  if l > nextL
    then (nr, l)
    else (nextNr, nextL)
  where
    (nextNr, nextL) = findLongest xs

main = do
  let eulerProblem = 14
      (collatzList, _) = collatzLengthsForList [1 .. 999_999] (Map.empty :: CollatzMap)
      (solution, m) = findLongest collatzList
  E.printProblemSolution eulerProblem solution
