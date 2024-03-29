-- Write your MySQL query statement below

SELECT S.user_id,
       round(sum(if(C.action = "confirmed", 1, 0)) / sum(1), 2) AS confirmation_rate
FROM Signups S
LEFT JOIN Confirmations C ON C.user_id = S.user_id
GROUP BY S.user_id