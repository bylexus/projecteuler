module Main (main) where

import Data.Maybe (mapMaybe)
import EulerLib qualified as E
import Problem0001 qualified as P1
import Problem0002 qualified as P2
import Problem0003 qualified as P3
import Problem0004 qualified as P4
import Problem0005 qualified as P5
import Problem0006 qualified as P6
import Problem0007 qualified as P7
import Problem0008 qualified as P8
import Problem0009 qualified as P9
import Problem0010 qualified as P10
import Problem0011 qualified as P11
import Problem0012 qualified as P12
import Problem0013 qualified as P13
import Problem0014 qualified as P14
import Problem0015 qualified as P15
import Problem0016 qualified as P16
import Problem0017 qualified as P17
import Problem0018 qualified as P18
import Problem0019 qualified as P19
import Problem0020 qualified as P20
import Problem0021 qualified as P21
import Problem0022 qualified as P22
import Problem0023 qualified as P23
import Problem0024 qualified as P24
import Problem0067 qualified as P67
import System.Environment (getArgs)

getProblem :: Int -> Maybe E.ProblemSolution
getProblem 1 = Just P1.solution
getProblem 2 = Just P2.solution
getProblem 3 = Just P3.solution
getProblem 4 = Just P4.solution
getProblem 5 = Just P5.solution
getProblem 6 = Just P6.solution
getProblem 7 = Just P7.solution
getProblem 8 = Just P8.solution
getProblem 9 = Just P9.solution
getProblem 10 = Just P10.solution
getProblem 11 = Just P11.solution
getProblem 12 = Just P12.solution
getProblem 13 = Just P13.solution
getProblem 14 = Just P14.solution
getProblem 15 = Just P15.solution
getProblem 16 = Just P16.solution
getProblem 17 = Just P17.solution
getProblem 18 = Just P18.solution
getProblem 19 = Just P19.solution
getProblem 20 = Just P20.solution
getProblem 21 = Just P21.solution
getProblem 22 = Just P22.solution
getProblem 23 = Just P23.solution
getProblem 24 = Just P24.solution
getProblem 67 = Just P67.solution
getProblem _ = Nothing

runProblem :: E.ProblemSolution -> IO ()
runProblem problem = do
  input <- E.psReadInput problem
  let solution = E.psSolve problem input
      solved = problem {E.psSolution = solution}
  E.printProblemSolution solved

main :: IO [()]
main = do
  args <- getArgs
  let problemNrs = map (read :: String -> Int) args
      problems = mapMaybe getProblem problemNrs
  mapM runProblem problems
