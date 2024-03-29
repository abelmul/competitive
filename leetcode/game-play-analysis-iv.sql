-- Write your MySQL query statement below

SELECT ROUND(COUNT(DISTINCT A.player_id) /
               (SELECT COUNT(DISTINCT player_id)
                FROM Activity), 2) AS fraction
FROM Activity A
JOIN
  (SELECT player_id,
          MIN(event_date) AS event_date
   FROM Activity
   GROUP BY player_id) A2 ON A.player_id = A2.player_id
AND A.event_date = A2.event_date
JOIN Activity A1 ON A2.player_id = A1.player_id
AND DATEDIFF(A1.event_date, A2.event_date) = 1