-- Write your MySQL query statement below

SELECT sell_date,
       count(DISTINCT product) AS num_sold,
       group_concat(DISTINCT product
                    order by product SEPARATOR ',') AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date