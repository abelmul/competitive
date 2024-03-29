-- Write your MySQL query statement below

SELECT product_name,
       sum(unit) AS unit
FROM Products P
JOIN Orders O ON P.product_id = O.product_id
AND O.order_date >="2020-02-01"
AND O.order_date < "2020-03-01"
GROUP BY P.product_id
HAVING sum(unit) >= 100