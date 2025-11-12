# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
FROM VIEWS AS v
WHERE v.author_id=viewer_id 
ORDER BY (author_id) 

