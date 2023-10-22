module Problem0023 (solution) where

{--------------------------------------------------------------------
<p>A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of $28$ would be $1 + 2 + 4 + 7 + 14 = 28$, which means that $28$ is a perfect number.</p>
<p>A number $n$ is called deficient if the sum of its proper divisors is less than $n$ and it is called abundant if this sum exceeds $n$.</p>

<p>As $12$ is the smallest abundant number, $1 + 2 + 3 + 4 + 6 = 16$, the smallest number that can be written as the sum of two abundant numbers is $24$. By mathematical analysis, it can be shown that all integers greater than $28123$ can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.</p>
<p>Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.</p>
---------------------------------------------------------------------}

import Data.IntSet qualified as Set
import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 23,
      E.psTitle = "Non-Abundant Sums",
      E.psSolve = \_ -> show calcSolution,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

calcSolution :: Int
calcSolution = sum checkedNrs

maxNr :: Int
maxNr = 28123

abundantNumbers :: [Int]
abundantNumbers = map fst (filter (\(x, sumDivs) -> sumDivs > x) (map (\x -> (x, sum (E.divisors x))) [12 .. maxNr]))

-- | A set containing all the abundant numbers from 1 to maxNr
-- | I use a set, as I have to look them up fast (contains)
abundantSet :: Set.IntSet
abundantSet = Set.fromList abundantNumbers

-- | A list of numbers and a list of smaller abundant numbers as that number: I need
-- | to check if the number can be built by the sum of the set of smaller abundant numbers
nrsWithAbundantsToCheck :: [(Int, [Int])]
nrsWithAbundantsToCheck = map (\x -> (x, filter (< x) abundantNumbers)) [1 .. maxNr]

-- | That's a mouthful... The checkedNumbers list contains only numbers that cannot
-- | be built by a sum of 2 smaller abundant numbers.
checkedNrs :: [Int]
checkedNrs = map fst onlyNunSummableNrs
  where
    nrsCanBeSummed = map (\(nr, lst) -> (nr, isSumOfAbundantNumbers lst nr)) nrsWithAbundantsToCheck
    onlyNunSummableNrs = filter (\(_, isSum) -> not isSum) nrsCanBeSummed


isAbundantNr :: Int -> Bool
isAbundantNr nr = Set.member nr abundantSet

isSumOfAbundantNumbers :: [Int] -> Int -> Bool
isSumOfAbundantNumbers abundantNrs testNr = any (\x -> isAbundantNr (testNr - x)) abundantNrs
