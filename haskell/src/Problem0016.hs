module Problem0016 (solution) where

{--------------------------------------------------------------------
<p>$2^{15} = 32768$ and the sum of its digits is $3 + 2 + 7 + 6 + 8 = 26$.</p>
<p>What is the sum of the digits of the number $2^{1000}$?</p>
---------------------------------------------------------------------}

import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 16,
      E.psTitle = "Power Digit Sum",
      E.psSolve = \_ -> (show . sum . E.toDigits) (2 ^ (1000 :: Integer)),
      E.psSolution = "",
      E.psReadInput = pure ""
    }
