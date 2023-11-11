-- Write your MySQL query statement below

select distinct P1.email as Email
from Person as P1
inner join Person as P2 on P1.email = P2.email
and P1.id != P2.id