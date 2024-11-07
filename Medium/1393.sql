# Write your MySQL query statement below

select stock_name, sum(net) as capital_gain_loss
from (select stock_name, (case when (operation = 'Buy') then -price else price end) as net from Stocks) as s
group by stock_name;