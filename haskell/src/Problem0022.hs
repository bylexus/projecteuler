module Problem0022 (solution) where

{--------------------------------------------------------------------
<p>Using <a href="resources/documents/0022_names.txt">names.txt</a> (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.</p>
<p>For example, when the list is sorted into alphabetical order, COLIN, which is worth $3 + 15 + 12 + 9 + 14 = 53$, is the $938$th name in the list. So, COLIN would obtain a score of $938 \times 53 = 49714$.</p>
<p>What is the total of all the name scores in the file?</p>
---------------------------------------------------------------------}

import Data.Char (ord)
import Data.List (sort)
import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 22,
      E.psTitle = "Names Scores",
      E.psSolve = show . calcSolution,
      E.psSolution = "",
      E.psReadInput = readFile "data_0022.txt"
    }

cleanName :: String -> String
cleanName = filter (/= '"')

nameToAlphaRanks :: String -> [Int]
nameToAlphaRanks = map (\c -> ord c - 64)

calcSolution :: String -> Int
calcSolution input = sum prods
  where
    names = E.splitAtChar ',' input
    sortedLines = (sort . map cleanName) names
    alphaRankSums = map (sum . nameToAlphaRanks) sortedLines
    indexedSums = zip [1 .. length alphaRankSums] alphaRankSums
    prods = map (\(order, nameSum) -> order * nameSum) indexedSums
