module Problem0067 (solution) where

{--------------------------------------------------------------------
<p>By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.</p>
<p class="monospace center"><span class="red"><b>3</b></span><br><span class="red"><b>7</b></span> 4<br>
2 <span class="red"><b>4</b></span> 6<br>
8 5 <span class="red"><b>9</b></span> 3</p>
<p>That is, 3 + 7 + 4 + 9 = 23.</p>
<p>Find the maximum total from top to bottom in <a href="resources/documents/0067_triangle.txt">triangle.txt</a> (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.</p>
<p class="smaller"><b>NOTE:</b> This is a much more difficult version of <a href="problem=18">Problem 18</a>. It is not possible to try every route to solve this problem, as there are 2<sup>99</sup> altogether! If you could check one trillion (10<sup>12</sup>) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)</p>
---------------------------------------------------------------------}

import Data.Map qualified as Map
import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 67,
      E.psTitle = "Maximum Path Sum II",
      E.psSolve = show . calcSolution,
      E.psSolution = "",
      E.psReadInput = readFile "data_0067.txt"
    }

lineToValues :: String -> [Int]
lineToValues = map (read :: String -> Int) . words

type MemoMap = Map.Map (Int, Int) Int

-- | solution with Memoization
-- | With Haskell, this is a bit tricky, as Memoization needs to keep a state between
-- | calls. I therefore "move" the memoization map as part of input/output.
maxSumMem :: MemoMap -> (Int, Int) -> E.Map2d Int -> (Int, MemoMap)
maxSumMem mMap (y, x) valueMap = (actValue, retMem)
  where
    storedValue = Map.lookup (y, x) mMap
    (actValue, retMem) = case storedValue of
      Just val -> (val, mMap)
      Nothing -> case Map.lookup (y, x) valueMap of
        Nothing -> (0, Map.insert (y, x) 0 mMap)
        Just val -> (val + greaterVal, Map.insert (y, x) (val + greaterVal) mem2)
    greaterVal = max leftVal rightVal
    -- here, we need the memMap 2 times, so I need an intermediate representation.
    -- Ugly, but with my limited Haskell knowledge, works.
    (leftVal, mem1) = maxSumMem mMap (y + 1, x) valueMap
    (rightVal, mem2) = maxSumMem mem1 (y + 1, x + 1) valueMap

calcSolution :: String -> Int
calcSolution input = s
  where
    rawValues = (map lineToValues . filter (/= "") . lines) input
    inputMap = E.listToCoordMap2 rawValues
    (s, _) = maxSumMem Map.empty (0, 0) inputMap
