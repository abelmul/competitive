-- Write your MySQL query statement below

select w.id
from Weather w
inner join Weather we on w.recordDate = DATE_ADD(we.recordDate , INTERVAL 1 DAY)
where w.temperature > we.temperature