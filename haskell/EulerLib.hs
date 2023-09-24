module EulerLib where

import Text.Printf (printf)

multipleOf :: (Integral a) => a -> a -> Bool
multipleOf multiplier test =
  mod test multiplier == 0

-- | return 'value' if the predicate function 'fn' returns true, else return the 'elseValue'.
valueIf :: (a -> Bool) -> a -> a -> a
valueIf fn value elseValue =
  if x
    then value
    else elseValue
  where
    x = fn value

-- | reduces a list to a value, by applying a function to the
--   intermediate result and the next list element.
--   Give:
--   fn: function that takes the next list value and the intermediate result
--   lst: The list to reduce
--   acc: The start value
reduce :: (a -> b -> b) -> [a] -> b -> b
reduce fn lst acc = case lst of
  [] -> acc
  (x : xs) -> fn x (reduce fn xs acc)

isDivisible :: Integer -> Integer -> Integer -> Bool
isDivisible from to testNr =
  if from <= to
    then
      if mod testNr from == 0
        then True
        else isDivisible (from + 1) to testNr
    else False

isPrime :: Integer -> Bool
isPrime nr
  | nr <= 1 = False
  | nr == 2 = True
  | otherwise = not (isDivisible 2 (ceiling (sqrt (fromIntegral nr))) nr)

-- | Prints a solution including its title. Give the problem number
--   and something that is Showable (the result).
printProblemSolution :: (Show b) => Integer -> b -> IO ()
printProblemSolution prob sol = putStrLn (printf "Problem %05d: " prob ++ show sol)
