# Write your MySQL query statement below

select (case when (id = (select count(*) from Seat) and ((select count(*) from Seat) % 2 = 1)) then id when (id % 2 = 1) then (id + 1) else (id - 1) end) as id, student from Seat order by id;