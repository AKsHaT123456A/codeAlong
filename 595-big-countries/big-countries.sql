# Write your MySQL query statement below
select name, area ,population from World
where area>=3000000 
union 
select name, area ,population from World
where population>=25000000