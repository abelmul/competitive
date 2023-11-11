-- Write your MySQL query statement below

SELECT M.employee_id,
       M.name,
       sum(1) AS reports_count,
       round(avg(E.age)) AS average_age
FROM Employees M
JOIN Employees E ON M.employee_id = E.reports_to
GROUP BY M.employee_id
ORDER BY M.employee_id