{--------------------------------------------------------------------
<p>The prime factors of $13195$ are $5, 7, 13$ and $29$.</p>
<p>What is the largest prime factor of the number $600851475143$?</p>
---------------------------------------------------------------------}
import Debug.Trace (trace)
import EulerLib

largestPrimeFactor :: [Integer] -> Integer -> Integer
largestPrimeFactor lst target
  | factor > target = 0 -- oops, should never happen.
  | target == factor = factor -- we reached the prime itself
  | mod target factor == 0 = largestPrimeFactor lst (div target factor) -- we can divide by the actual prime - continue with the reduced target
  | otherwise = largestPrimeFactor (tail lst) target -- we could not divide - means the actual prime is exhausted, take the next
  where
    factor = head lst

main =
  let eulerProblem = 3
      input = filter EulerLib.isPrime [2 ..] -- infinite list of primes
      solution = largestPrimeFactor input 600_851_475_143
   in EulerLib.printProblemSolution eulerProblem solution
