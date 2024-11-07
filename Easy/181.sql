# Write your MySQL query statement below


with t as 
    (
        select a.name as emp_name, a.salary as emp_salary, b.name as manager_name, b.salary as manager_salary 
        from Employee as a left join Employee as b 
        on a.managerId = b.id
    )
select emp_name as Employee from t where (manager_salary is not null) and (emp_salary > manager_salary);