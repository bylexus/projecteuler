module Problem0024 (solution) where

{--------------------------------------------------------------------
<p>A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:</p>
<p class="center">012   021   102   120   201   210</p>
<p>What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?</p>
---------------------------------------------------------------------}

import EulerLib qualified as E
import Combinatorics qualified as C

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 24,
      E.psTitle = "Lexicographic Permutations",
      E.psSolve = \_ -> show millionth,
      E.psSolution = "",
      E.psReadInput = pure ""
    }


-- For this problem, I cheated a bit: I used an external library to create the
-- list permutations, then it is simple:
millionth :: String
millionth = (C.permute "0123456789") !! 999_999