module Problem0019 (solution) where

{--------------------------------------------------------------------
<p>You are given the following information, but you may prefer to do some research for yourself.</p>
<ul><li>1 Jan 1900 was a Monday.</li>
<li>Thirty days has September,<br />
April, June and November.<br />
All the rest have thirty-one,<br />
Saving February alone,<br />
Which has twenty-eight, rain or shine.<br />
And on leap years, twenty-nine.</li>
<li>A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.</li>
</ul><p>How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?</p>
---------------------------------------------------------------------}

import Data.Maybe (fromJust)
import Data.Time.Calendar
import Data.Time.Format
import EulerLib qualified as E

solution :: E.ProblemSolution
solution =
  E.ProblemSolution
    { E.psNr = 19,
      E.psTitle = "Counting Sundays",
      E.psSolve = \_ -> show solutionNr,
      E.psSolution = "",
      E.psReadInput = pure ""
    }

startDay :: Day
startDay = fromJust (parseTimeM True defaultTimeLocale "%Y-%-m-%-d" "1901-01-01" :: Maybe Day)

endDay :: Day
endDay = fromJust (parseTimeM True defaultTimeLocale "%Y-%-m-%-d" "2000-12-31" :: Maybe Day)

dayList :: [Day]
dayList = [addDays x startDay | x <- [0 .. (diffDays endDay startDay)]]

onlySundays :: [Day]
onlySundays = filter (\x -> dayOfWeek x == Sunday) dayList

dayOfMonth :: [String]
dayOfMonth = map (formatTime defaultTimeLocale "%d") onlySundays

only1Sundays :: [String]
only1Sundays = filter (== "01") dayOfMonth

solutionNr :: Int
solutionNr = length only1Sundays
