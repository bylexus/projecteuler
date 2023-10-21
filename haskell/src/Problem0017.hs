module Problem0017 (solution) where

{--------------------------------------------------------------------
<p>If the numbers $1$ to $5$ are written out in words: one, two, three, four, five, then there are $3 + 3 + 5 + 4 + 4 = 19$ letters used in total.</p>
<p>If all the numbers from $1$ to $1000$ (one thousand) inclusive were written out in words, how many letters would be used? </p>
<br><p class="note"><b>NOTE:</b> Do not count spaces or hyphens. For example, $342$ (three hundred and forty-two) contains $23$ letters and $115$ (one hundred and fifteen) contains $20$ letters. The use of "and" when writing out numbers is in compliance with British usage.</p>
---------------------------------------------------------------------}

import Data.Map qualified as Map
import Data.Maybe (fromJust)
import EulerLib (trim)
import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 17,
      E.psTitle = "Number Letter Counts",
      E.psSolve = show . calcSolution,
      E.psSolution = "",
      E.psReadInput = readFile "data_0017.txt"
    }

nrToWords :: Map.Map Int String -> Int -> String
nrToWords wMap n
  | n < 1 = ""
  | n < 20 = fromJust (Map.lookup n wMap)
  | n < 100 && n `mod` 10 == 0 = fromJust (Map.lookup n wMap)
  | n < 100 = nrToWords wMap ((n `div` 10) * 10) ++ nrToWords wMap (n `mod` 10)
  | n < 1000 =
      let hundredVal = (n `div` 100)
          rest = n `mod` 100
          hundred = fromJust (Map.lookup 100 wMap)
          and =
            if rest > 0
              then "and"
              else ""
          lowerPart =
            if rest > 0
              then nrToWords wMap rest
              else ""
       in nrToWords wMap hundredVal ++ hundred ++ and ++ lowerPart
  | n < 10000 =
      let thousandVal = (n `div` 1000)
          rest = n `mod` 1000
          thousand = fromJust (Map.lookup 1000 wMap)
          lowerPart =
            if rest > 0
              then nrToWords wMap rest
              else ""
       in nrToWords wMap thousandVal ++ thousand ++ lowerPart
  | otherwise = "Unknown"

calcSolution :: String -> Int
calcSolution input = (sum . map length) nrOfWords
  where
    l = lines input
    pairs = map (\l -> (read (l !! 0) :: Int, trim (l !! 1))) (map (E.splitAtChar ':') l)
    wordMap = Map.fromList pairs
    mappedNrToWords = nrToWords wordMap
    inputList = [1 .. 1000]
    nrOfWords = map mappedNrToWords inputList
