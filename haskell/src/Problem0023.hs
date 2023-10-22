module Problem0023 (solution) where

{--------------------------------------------------------------------
<p>A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of $28$ would be $1 + 2 + 4 + 7 + 14 = 28$, which means that $28$ is a perfect number.</p>
<p>A number $n$ is called deficient if the sum of its proper divisors is less than $n$ and it is called abundant if this sum exceeds $n$.</p>

<p>As $12$ is the smallest abundant number, $1 + 2 + 3 + 4 + 6 = 16$, the smallest number that can be written as the sum of two abundant numbers is $24$. By mathematical analysis, it can be shown that all integers greater than $28123$ can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.</p>
<p>Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E
import Data.Map qualified as Map
import Data.Maybe (isJust)

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 23,
      E.psTitle = "Non-Abundant Sums",
      E.psSolve = show . calcSolution,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

isAbundantNr :: Map.Map Int Int -> Int -> Bool
isAbundantNr nrMap nr = isJust (Map.lookup nr nrMap)

isSumOfAbundantNumbers :: Map.Map Int Int -> [Int] -> Int -> Bool
isSumOfAbundantNumbers nrMap abundantNrs testNr = any (\x -> isAbundantNr nrMap (testNr - x)) abundantNrs

-- calcSolution :: String -> Int
calcSolution _ = s
  where
    maxNr = 28123
    -- maxNr = 100
    -- abundantNumbers = map (\x -> (x, sum (E.divisors x))) [1 .. 28123]
    abundantNumbers = map fst (filter (\(x, sumDivs) -> sumDivs > x) (map (\x -> (x, sum (E.divisors x))) [12 .. maxNr]))
    abundantMap = Map.fromList (map (\x -> (x, x)) abundantNumbers)
    nrsWithAbundantsToCheck = map (\x -> (x, filter (< x) abundantNumbers)) [1 .. maxNr]
    checkedNrs = map (\(nr, lst) -> (nr, isSumOfAbundantNumbers abundantMap lst nr)) nrsWithAbundantsToCheck
    filteredPairs = filter (\(_, isSum) -> not isSum) checkedNrs
    filteredNrs = map fst filteredPairs
    -- sumOf2AbundantNumbers =  [x + y | x <- abundantNumbers, y <- abundantNumbers, x <= y && x + y < maxNr]
    -- nonSumsOf2Abundant = filter (\x -> () ) [1 .. maxNr]
    -- s = sum nonSumsOf2Abundant
    s = sum filteredNrs
