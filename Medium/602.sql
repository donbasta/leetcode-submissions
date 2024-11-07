# Write your MySQL query statement below

select id, num from (
select s1.requester_id as id, (ifnull(s1.cnt, 0) + ifnull(s2.cnt, 0)) as num from
(select requester_id, count(*) as cnt from RequestAccepted group by requester_id) s1 left join
(select accepter_id, count(*) as cnt from RequestAccepted group by accepter_id) s2 
on s1.requester_id = s2.accepter_id

union

select s2.accepter_id as id, (ifnull(s1.cnt, 0) + ifnull(s2.cnt, 0)) as num from
(select accepter_id, count(*) as cnt from RequestAccepted group by accepter_id) s2 left join
(select requester_id, count(*) as cnt from RequestAccepted group by requester_id) s1
on s2.accepter_id = s1.requester_id
) s3 

order by num desc limit 1;

