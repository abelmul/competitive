-- Write your MySQL query statement below

SELECT query_name,
       ROUND(AVG(rating/POSITION), 2) AS quality,
       ROUND(sum(if(rating < 3, 1, 0))/count(rating)*100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name