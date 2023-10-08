{--------------------------------------------------------------------
<p>The four adjacent digits in the $1000$-digit number that have the greatest product are $9 \times 9 \times 8 \times 9 = 5832$.</p>
<p class="monospace center">
73167176531330624919225119674426574742355349194934<br>
96983520312774506326239578318016984801869478851843<br>
85861560789112949495459501737958331952853208805511<br>
12540698747158523863050715693290963295227443043557<br>
66896648950445244523161731856403098711121722383113<br>
62229893423380308135336276614282806444486645238749<br>
30358907296290491560440772390713810515859307960866<br>
70172427121883998797908792274921901699720888093776<br>
65727333001053367881220235421809751254540594752243<br>
52584907711670556013604839586446706324415722155397<br>
53697817977846174064955149290862569321978468622482<br>
83972241375657056057490261407972968652414535100474<br>
82166370484403199890008895243450658541227588666881<br>
16427171479924442928230863465674813919123162824586<br>
17866458359124566529476545682848912883142607690042<br>
24219022671055626321111109370544217506941658960408<br>
07198403850962455444362981230987879927244284909188<br>
84580156166097919133875499200524063689912560717606<br>
05886116467109405077541002256983155200055935729725<br>
71636269561882670428252483600823257530420752963450<br></p>
<p>Find the thirteen adjacent digits in the $1000$-digit number that have the greatest product. What is the value of this product?</p>
---------------------------------------------------------------------}

import Data.Maybe (catMaybes, isJust, mapMaybe)
import Data.Monoid (Product (Product))
import Data.String
import EulerLib qualified as E

readInput = do
  readFile "data_0008.txt"

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

movingWindowList :: Int -> String -> [String]
movingWindowList groupSize xs =
  if length xs < groupSize
    then []
    else take groupSize xs : movingWindowList groupSize (tail xs)

productOfDigits :: String -> Maybe Int
productOfDigits [] = Nothing
productOfDigits [digit] = charToDigit digit
productOfDigits (digit : xs) = prodMaybe intDigit prodRest
  where
    intDigit = charToDigit digit
    prodRest = productOfDigits xs
    prodMaybe :: Maybe Int -> Maybe Int -> Maybe Int
    prodMaybe (Just a) (Just b) = Just (a * b)
    prodMaybe _ _ = Nothing

onlyJust = filter isJust

prodOfList :: [Maybe Int] -> Int
prodOfList list = product $ catMaybes list

main = do
  input <- readInput
  let windowSize = 13
  let solution = maximum (mapMaybe productOfDigits (movingWindowList windowSize (E.trim input)))
  let eulerProblem = 8
  E.printProblemSolution eulerProblem solution
