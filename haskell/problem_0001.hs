import EulerLib

-- | Checks if the given value is a multiple of 5
multipleOf5 = EulerLib.multipleOf 5

-- | Checks if the given value is a multiple of 3
multipleOf3 = EulerLib.multipleOf 3

-- | Checks if the given value is a multiple of 3 OR 5
multipleOf3Or5 x = multipleOf3 x || multipleOf5 x

main =
  let eulerProblem = 1
      input = [1 .. 999]
      solution = sum (map (\x -> EulerLib.valueIf multipleOf3Or5 x 0) input)
   in EulerLib.printProblemSolution eulerProblem solution