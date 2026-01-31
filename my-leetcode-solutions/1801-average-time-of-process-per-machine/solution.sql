# Write your MySQL query statement below
SELECT machine_id, ROUND(AVG(process_time), 3) as processing_time
FROM (
    SELECT machine_id,
    MAX(CASE WHEN activity_type = 'end' THEN timestamp END) -
        MIN(CASE WHEN activity_type = 'start' THEN timestamp END)
    AS process_time
    FROM Activity
    GROUP BY machine_id,process_id
) t
GROUP BY machine_id;

