-- Write your PostgreSQL query statement below
SELECT score, rank
FROM (
    SELECT score,
        DENSE_RANK() OVER (ORDER BY score DESC) as rank
    FROM Scores
) t;
