module Problem0010 (solution) where

{--------------------------------------------------------------------
<p>The sum of the primes below $10$ is $2 + 3 + 5 + 7 = 17$.</p>
<p>Find the sum of all the primes below two million.</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 10,
      E.psTitle = "Summation of Primes",
      E.psSolve = \_ -> show $ (sum . takeWhile (< border)) E.primeList,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

border :: Integer
border = 2_000_000 :: Integer
