-- Duplicate Emails
-- https://leetcode.com/problems/duplicate-emails/
-- Accepted 2023-07-15 | Runtime 935 ms | Memory 0B

# Write your MySQL query statement below
SELECT email AS Email FROM Person GROUP BY email HAVING COUNT(*) > 1