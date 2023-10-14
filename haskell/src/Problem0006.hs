module Problem0006 (solution) where

{--------------------------------------------------------------------
<p>The sum of the squares of the first ten natural numbers is,</p>
\$$1^2 + 2^2 + ... + 10^2 = 385.$$
<p>The square of the sum of the first ten natural numbers is,</p>
\$$(1 + 2 + ... + 10)^2 = 55^2 = 3025.$$
<p>Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is $3025 - 385 = 2640$.</p>
<p>Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.</p>
---------------------------------------------------------------------}
import EulerLib qualified as E

solution =
  E.ProblemSolution
    { E.psNr = 6,
      E.psTitle = "Sum Square Difference",
      E.psSolve = \_ -> show $ abs $ sum (map (^ 2) [1 .. nr]) - sum [1 .. nr] ^ 2,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

nr :: Int
nr = 100
