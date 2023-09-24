import EulerLib

-- | Creates a Fibonacchi sequence by extending the given List
--   up to a certain maximum value in the sequence.
fiboTo :: Integer -> [Integer]
fiboTo max
  | max < 1 = []
  | max == 1 = [1]
  | max == 2 = [1, 2]
  | max == 3 = [1, 2, 3]
  | max > 3 = reverse (_fiboTo [3, 2, 1] max)

-- | internal Helper function to fiboTo:
--   generates a list of fibonacchi elements up to a certain max value,
--   by appending to the front. MUST be started with [3,2,1].
_fiboTo :: [Integer] -> Integer -> [Integer]
_fiboTo lst max = case lst of
  (a : b : xs) ->
    if a + b < max
      then _fiboTo (a + b : lst) max
      else lst

evenList :: [Integer] -> [Integer]
evenList = filter even

main =
  let eulerProblem = 1
      input = []
      solution = sum (evenList (fiboTo 4_000_000))
   in EulerLib.printProblemSolution eulerProblem solution