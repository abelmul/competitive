-- Write your MySQL query statement below

SELECT P.product_id,
       IFNULL(ROUND(sum(price*units)/sum(units), 2), 0) AS average_price
FROM Prices P
LEFT JOIN UnitsSold US ON US.product_id = P.product_id
AND purchase_date BETWEEN start_date AND end_date
GROUP BY product_id