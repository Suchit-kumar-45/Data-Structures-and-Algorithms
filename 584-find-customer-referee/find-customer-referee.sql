# Write your MySQL query statement below
SELECT c.name AS name 
FROM Customer c
WHERE c.referee_id IS NULL OR c.referee_id != 2
