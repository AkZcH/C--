# Write your MySQL query statement below
SELECT DISTINCT l1.num as ConsecutiveNums
FROM Logs as l1
JOIN Logs as l2
    ON l2.id = l1.id + 1 AND l1.num = l2.num
JOIN Logs as l3
    ON l3.id = l2.id + 1 AND l2.num = l3.num

