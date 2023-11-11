-- Write your MySQL query statement below

SELECT R.contest_id,
       round((count(user_id) /
                (SELECT count(user_id)
                 FROM Users))*100, 2) AS percentage
FROM Register R
GROUP BY R.contest_id
ORDER BY percentage DESC,
         R.contest_id ASC