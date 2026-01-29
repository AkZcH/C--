-- Write your PostgreSQL query statement below
SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN(
        SELECT DepartmentId, max(salary) AS max_salary
        FROM Employee e
        GROUP BY departmentId
) dm
    ON e.departmentId = dm.departmentId
    AND e.salary = dm.max_salary
    JOIN Department as d
    ON e.departmentId = d.id

