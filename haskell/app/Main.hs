module Main (main) where

import EulerLib qualified as E
import Problem0001 qualified as P1
import Problem0002 qualified as P2
import Problem0003 qualified as P3
import System.Environment (getArgs)

solveNr :: Int -> Maybe E.ProblemSolution
solveNr 1 = Just $ solveProb P1.P
solveNr 2 = Just $ solveProb P2.P
solveNr 3 = Just $ solveProb P3.P
solveNr _ = Nothing

solveProb :: (E.EulerProblem a) => a -> E.ProblemSolution
solveProb p =
  E.ProblemSolution
    { E.psNr = E.problemNr p,
      E.psTitle = E.title p,
      E.psSolution = E.solution p
    }

main :: IO [()]
main = do
  args <- getArgs
  let problemNrs = map (read :: String -> Int) args
      solutions = map solveNr problemNrs
  mapM E.printProblemSolution solutions
