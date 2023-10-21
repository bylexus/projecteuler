module Problem0013 (solution) where

{--------------------------------------------------------------------
<p>Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.</p>
(see data_0013.txt)
---------------------------------------------------------------------}

import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 13,
      E.psTitle = "Large Sum",
      E.psSolve = calcSolution,
      E.psSolution = "",
      E.psReadInput = do readFile "data_0013.txt"
    }

calcSolution :: String -> String
calcSolution input = result
  where
    linesToInteger = map (\x -> read x :: Integer) . lines
    numbers = linesToInteger input
    sumStr = show $ sum numbers
    result = take 10 sumStr
