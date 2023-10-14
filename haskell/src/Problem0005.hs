module Problem0005 (solution) where

{--------------------------------------------------------------------
<p>$2520$ is the smallest number that can be divided by each of the numbers from $1$ to $10$ without any remainder.</p>
<p>What is the smallest positive number that is <dfn class="tooltip">evenly divisible<span class="tooltiptext">divisible with no remainder</span></dfn> by all of the numbers from $1$ to $20$?</p>
---------------------------------------------------------------------}
import EulerLib qualified as E

solution =
  E.ProblemSolution
    { E.psNr = 5,
      E.psTitle = "Smallest Multiple",
      E.psSolve = \_ -> show $ findDivByAll 20 20,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

-- | Checks if the number nr is evenly divisable by all numbers from 1 to n
divisibleByAll :: Integer -> Integer -> Bool
divisibleByAll 1 _ = True
divisibleByAll n nr = mod nr n == 0 && divisibleByAll (n - 1) nr

-- | Finds the smalles number that is evenly divisible by all numbers from 1 to divisor,
--   starting from 'dividend' and increasing by divisor.
--   Example: findDivByAll 20 10 starts with the number 20, and increases it with 10
--   until the resulting number is evenly divisible through all numbers from 1 to 10.
findDivByAll :: Integer -> Integer -> Integer
findDivByAll dividend divisor =
  if divisibleByAll divisor dividend
    then dividend
    else findDivByAll (dividend + divisor) divisor
