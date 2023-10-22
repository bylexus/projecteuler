module Problem0002 (solution) where

{--------------------------------------------------------------------
<p>Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with $1$ and $2$, the first $10$ terms will be:
\$$1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \dots$$</p>
<p>By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.</p>
---------------------------------------------------------------------}
import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 2,
      E.psTitle = "Even Fibonacci Numbers",
      E.psSolve = \_ -> show $ sum (evenList (E.fiboTo (>= 4_000_000))),
      E.psSolution = "",
      E.psReadInput = pure ""
    }

evenList :: [Integer] -> [Integer]
evenList = filter even
