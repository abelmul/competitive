-- Write your MySQL query statement below

SELECT Q.person_name
FROM Queue Q
JOIN Queue Q1 ON Q1.turn <= Q.turn
GROUP BY Q.turn
HAVING sum(Q1.weight) <= 1000
ORDER BY Q.turn DESC
LIMIT 1