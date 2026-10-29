-- Employees Earning More Than Their Managers
-- https://leetcode.com/problems/employees-earning-more-than-their-managers/
-- Accepted 2023-07-15 | Runtime 754 ms | Memory 0B

# Write your MySQL query statement below
SELECT emp.name AS Employee FROM Employee emp, Employee emp1 where emp.salary>emp1.salary AND emp1.id=emp.managerId 