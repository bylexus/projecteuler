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
