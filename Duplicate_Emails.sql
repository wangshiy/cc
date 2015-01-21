/*
Problem:
Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Note: All emails are in lowercase.
*/

# Write your MySQL query statement below
select P1.Email
from Person P1
inner join Person P2
on P1.Email = P2.Email
group by P1.Email
having count(P1.Email) > 1