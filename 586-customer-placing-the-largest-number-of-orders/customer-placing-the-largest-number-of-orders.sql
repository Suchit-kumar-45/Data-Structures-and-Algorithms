# Write your MySQL query statement below
SELECT o.customer_number
AS customer_number 
FROM Orders o
GROUP BY customer_number
ORDER BY count(order_number) DESC
LIMIT 1


