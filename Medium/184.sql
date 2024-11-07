# Write your MySQL query statement below

select Department.name Department, Employee.name Employee, Employee.salary Salary from
(select max(salary) as MaxSalary, departmentId from Employee group by departmentId) s1
join Department on s1.departmentId = Department.id
join Employee on Employee.salary = s1.MaxSalary and Employee.departmentId = Department.id;