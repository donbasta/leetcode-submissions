# Write your MySQL query statement below

-- select sum(case when O = C then 1 else 0 end) * 100 / count(*) as immediate_percentage from Delivery
-- where () (select customer_id, min(order_date) as O, customer_pref_delivery_date as C from Delivery group by customer_id) as S;

-- select * from
-- (select customer_id, min(order_date) as O, customer_pref_delivery_date as C from Delivery group by customer_id) as S
-- where O = C;

-- select customer_id, min(order_date) as O, customer_pref_delivery_date as C from Delivery group by customer_id;

select round(sum(case when order_date = customer_pref_delivery_date then 1 else 0 end) * 100 / count(*), 2) as immediate_percentage 
from Delivery
where (customer_id, order_date) in (select customer_id, min(order_date) from Delivery group by customer_id);