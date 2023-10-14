module Problem0003 (solution) where

{--------------------------------------------------------------------
<p>The prime factors of $13195$ are $5, 7, 13$ and $29$.</p>
<p>What is the largest prime factor of the number $600851475143$?</p>
---------------------------------------------------------------------}
import EulerLib qualified as E

solution =
  E.ProblemSolution
    { E.psNr = 3,
      E.psTitle = "Largest Prime Factor",
      E.psSolve = \_ -> show $ largestPrimeFactor input 600_851_475_143,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

data Problem = P deriving (Show)

input = filter E.isPrime [2 ..] -- infinite list of primes

largestPrimeFactor :: [Integer] -> Integer -> Integer
largestPrimeFactor lst target
  | factor > target = 0 -- oops, should never happen.
  | target == factor = factor -- we reached the prime itself
  | mod target factor == 0 = largestPrimeFactor lst (div target factor) -- we can divide by the actual prime - continue with the reduced target
  | otherwise = largestPrimeFactor (tail lst) target -- we could not divide - means the actual prime is exhausted, take the next
  where
    factor = head lst
