-- Customers Who Never Order
-- https://leetcode.com/problems/customers-who-never-order/
-- Accepted 2023-07-15 | Runtime 1240 ms | Memory 0B

# Write your MySQL query statement below
SELECT name AS Customers FROM Customers WHERE Customers.id NOT IN (SELECT customerId from Orders)