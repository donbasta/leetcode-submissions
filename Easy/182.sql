# Write your MySQL query statement below


select email as Email from (select email, count(email) as cnt from Person group by email) as s where cnt > 1;