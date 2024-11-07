# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

# select count(email) as cnt, email from Person group by email;


delete from Person
    where id not in (select * from (select min(id) from Person group by email) as p);