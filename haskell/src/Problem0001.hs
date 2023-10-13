module Problem0001 where

{--------------------------------------------------------------------
<p>If we list all the natural numbers below $10$ that are multiples of $3$ or $5$, we get $3, 5, 6$ and $9$. The sum of these multiples is $23$.</p>
<p>Find the sum of all the multiples of $3$ or $5$ below $1000$.</p>
---------------------------------------------------------------------}
import EulerLib qualified as E

data Problem = P deriving (Show)

instance E.EulerProblem Problem where
  problemNr _ = 1
  title _ = "Multiples of 3 or 5"
  solution :: Problem -> String
  solution _ = solution
    where
      input = [1 .. 999]
      solution = show (sum (map (\x -> E.valueIf multipleOf3Or5 x 0) input))

-- | Checks if the given value is a multiple of 5
multipleOf5 :: Integer -> Bool
multipleOf5 = E.multipleOf 5

-- | Checks if the given value is a multiple of 3
multipleOf3 :: Integer -> Bool
multipleOf3 = E.multipleOf 3

-- | Checks if the given value is a multiple of 3 OR 5
multipleOf3Or5 :: Integer -> Bool
multipleOf3Or5 x = multipleOf3 x || multipleOf5 x
