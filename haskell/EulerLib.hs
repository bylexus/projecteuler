module EulerLib where

import Data.Char (isSpace)
import Data.List (dropWhileEnd, nub)
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

-- | Checks if the given number testNr is divisible of any of the
--   numbers from 'from' to 'to'.
isDivisible :: (Integral a) => a -> a -> a -> Bool
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

-- | An infinite list of primes. Make sure to limit it if you take elements of it.
-- | TODO: Maybe we can implement that more efficient by using the sieve of Eratosthenes?
primeList = filter isPrime [2 ..]

-- | Prints a solution including its title. Give the problem number
--   and something that is Showable (the result).
printProblemSolution :: (Show b) => Integer -> b -> IO ()
printProblemSolution prob sol = putStrLn (printf "Problem %05d: " prob ++ show sol)

-- | Return the last n elements of a list
lastN :: Integer -> [a] -> [a]
lastN 0 _ = []
lastN _ [] = []
lastN n lst = lastN (n - 1) (init lst) ++ [last lst]

-- | Return the first n elements of a list
headN :: Integer -> [a] -> [a]
headN 0 _ = []
headN _ [] = []
headN n (x : xs) = x : headN (n - 1) xs

-- | Takes an Integer and returns a list of its single digits.
toDigits :: Integer -> [Integer]
toDigits n
  | n < 0 = toDigits $ n * (-1)
  | n < 10 = [n]
  | otherwise = toDigits (div n 10) ++ [mod n 10]

-- | Takes a fn and two lists a and b, and returns the combination of all elements
--   from list a with all elements from list b, by applying fn(a, b) for each combination.
--   Aka "cross product", or cartesian product
--
--   Example:
--   cross (*) [1,2] [3,4] -> [1*3 = 3, 1*4 = 4, 2*3 = 6, 2*4 = 8]
cross :: (Integer -> Integer -> Integer) -> [Integer] -> [Integer] -> [Integer]
cross _ _ [] = []
cross _ [] _ = []
cross fn (a : as) b = map (fn a) b ++ cross fn as b

listMax :: [Integer] -> Integer
listMax [] = error "List cannot be empty"
listMax (a : as) = foldl max a as

trim = dropWhile isSpace . dropWhileEnd isSpace

-- | Converts a single char to its Int digit
charToDigit :: Char -> Maybe Int
charToDigit '0' = Just 0
charToDigit '1' = Just 1
charToDigit '2' = Just 2
charToDigit '3' = Just 3
charToDigit '4' = Just 4
charToDigit '5' = Just 5
charToDigit '6' = Just 6
charToDigit '7' = Just 7
charToDigit '8' = Just 8
charToDigit '9' = Just 9
charToDigit _ = Nothing

-- | returns only the unique items of a list.
unique :: (Eq a) => [a] -> [a]
unique = nub

splitAtChar :: Char -> String -> [String]
splitAtChar _ "" = []
splitAtChar chr str = leftPart : splitAtChar chr rightStr
  where
    (leftPart, rightPart) = break (== chr) str
    rightStr = if length rightPart > 0 
      then tail rightPart
      else rightPart
