-- Write your MySQL query statement below

SELECT round(sum(if(order_date = customer_pref_delivery_date, 1, 0))/count(order_date) * 100, 2) AS immediate_percentage
FROM Delivery D
JOIN
  (SELECT customer_id AS cid,
          min(order_date) AS miod
   FROM Delivery
   GROUP BY cid) M ON D.customer_id = M.cid
AND D.order_date = M.miod