# Write your MySQL query statement below

select x, y, z, if(x + y + z > 2 * greatest(x, y, z), "Yes", "No") as triangle from Triangle;