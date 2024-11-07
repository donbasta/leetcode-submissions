# Write your MySQL query statement below


select s1.product_id, ifnull(new_price, 10) as price from
(select distinct product_id from Products) s1 left join
(select * from Products where
(product_id, change_date) in 
(select product_id, max(change_date) 
from Products where change_date <= '2019-08-16' group by product_id)) s2
on s1.product_id = s2.product_id
;