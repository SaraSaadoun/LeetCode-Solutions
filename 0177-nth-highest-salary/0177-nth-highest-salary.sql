CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      with cte as (
      select salary, dense_rank() over(order by salary desc) as num from Employee
      )
      select salary from cte where num = N
      limit 1
      
      
      
  );
END