-- Write your MySQL query statement below

SELECT S.product_id,
       S.year AS first_year,
       quantity,
       price
FROM Sales S
JOIN
  (SELECT product_id,
          min(YEAR) AS YEAR
   FROM Sales
   GROUP BY product_id) SM ON S.product_id = SM.product_id
AND S.year = SM.year