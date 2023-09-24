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


printProblemSolution :: (Show b) => Integer -> b -> IO()
printProblemSolution prob sol = putStrLn (printf "Problem %05d: " prob ++ show sol)
