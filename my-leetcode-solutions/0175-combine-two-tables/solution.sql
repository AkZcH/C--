# Write your MySQL query statement below
SELECT p.firstName, p.LastName, a.city, a.state
FROM    Person P
    LEFT JOIN Address a
    ON p.personId = a.personId

