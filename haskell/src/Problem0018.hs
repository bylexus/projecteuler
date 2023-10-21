module Problem0018 (solution) where

{--------------------------------------------------------------------
<p>By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.</p>
<p class="monospace center"><span class="red"><b>3</b></span><br>
<span class="red"><b>7</b></span> 4<br>
2 <span class="red"><b>4</b></span> 6<br>
8 5 <span class="red"><b>9</b></span> 3</p>
<p>That is, 3 + 7 + 4 + 9 = 23.</p>
<p>Find the maximum total from top to bottom of the triangle below:</p>
<p class="monospace center">75<br>
95 64<br>
17 47 82<br>
18 35 87 10<br>
20 04 82 47 65<br>
19 01 23 75 03 34<br>
88 02 77 73 07 63 67<br>
99 65 04 28 06 16 70 92<br>
41 41 26 56 83 40 80 70 33<br>
41 48 72 33 47 32 37 16 94 29<br>
53 71 44 65 25 43 91 52 97 51 14<br>
70 11 33 28 77 73 17 78 39 68 17 57<br>
91 71 52 38 17 14 91 43 58 50 27 29 48<br>
63 66 04 68 89 53 67 30 73 16 69 87 40 31<br>
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23</p>
<p class="note"><b>NOTE:</b> As there are only 16384 routes, it is possible to solve this problem by trying every route. However, <a href="problem=67">Problem 67</a>, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)</p>

---------------------------------------------------------------------}

import Data.Map.Strict qualified as Map
import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 18,
      E.psTitle = "Maximum Path Sum I",
      E.psSolve = show . calcSolution,
      E.psSolution = "",
      E.psReadInput = readFile "data_0018.txt"
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
