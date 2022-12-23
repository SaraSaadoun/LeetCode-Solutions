/* Write your T-SQL query statement below */
with m(departmentId, max_salary) as (select departmentId, 
                    max(salary) 
            from Employee
            group by departmentId) 

select d.name as 'Department', e.name as 'Employee', max_salary as 'Salary'
from Employee as e inner join Department as d
on  e.departmentId = d.id
inner join m
on m.departmentId = e.departmentId
where e.salary = max_salary