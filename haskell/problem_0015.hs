{--------------------------------------------------------------------
<p>Starting in the top left corner of a $2 \times 2$ grid, and only being able to move to the right and down, there are exactly $6$ routes to the bottom right corner.</p>
<div class="center">
<img src="https://projecteuler.net/resources/images/0015.png?1678992052" class="dark_img" alt=""></div>
<p>How many such routes are there through a $20 \times 20$ grid?</p>
---------------------------------------------------------------------}

import Data.Map.Strict qualified as Map
import EulerLib qualified as E

type CoordCountMap = Map.Map (Int, Int) Int

-- | count the routes for a given coordinate, working with and returning a memoization
-- | map of already visited routes.
countRoutes :: (Int, Int) -> (Int, Int) -> CoordCountMap -> (Int, CoordCountMap)
countRoutes (x, y) (maxX, maxY) cMap
  -- final position: return 1
  | x == maxX && y == maxY = (1, cMap)
  -- out-of-bounds position: return 0 (no route)
  | x > maxX || y > maxY = (0, cMap)
  | otherwise = case actCount of
      -- already here once: just return the route count
      Just cnt -> (cnt, cMap)
      -- not yet here: sum the right + down route count and store:
      Nothing -> (cntAll, finalMap)
        where
          (cnt1, map1) = countRoutes (x, y + 1) (maxX, maxY) cMap
          (cnt2, map2) = countRoutes (x + 1, y) (maxX, maxY) map1
          cntAll = cnt1 + cnt2
          finalMap = Map.insert (x, y) cntAll map2
  where
    actCount = Map.lookup (x, y) cMap

main = do
  let eulerProblem = 15
      (solution, _) = countRoutes (0, 0) (20, 20) Map.empty
  E.printProblemSolution eulerProblem solution
