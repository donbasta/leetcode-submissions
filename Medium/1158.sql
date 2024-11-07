# Write your MySQL query statement below


select Users.user_id as buyer_id, Users.join_date, ifnull(s1.orders_in_2019, 0) as orders_in_2019
from Users left join
(select buyer_id, count(*) as orders_in_2019
from Orders
where year(order_date) = 2019
group by buyer_id) s1
on s1.buyer_id = Users.user_id;