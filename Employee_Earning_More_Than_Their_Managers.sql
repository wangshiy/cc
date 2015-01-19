/*
Problem:
The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.

+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+
Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.

+----------+
| Employee |
+----------+
| Joe      |
+----------+
*/

# Write your MySQL query statement below

/* Method 1
select E1.Name 
from Employee E1
inner join Employee E2
on E1.ManagerId = E2.Id
where E1.Salary > E2.Salary
*/

#Method 2
select E1.Name
from Employee E1
left join Employee E2
on E1.Salary > E2.Salary
where E1.ManagerId = E2.Id