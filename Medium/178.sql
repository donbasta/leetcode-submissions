
select Scores.score, `rank` from Scores join (select score, @rank := @rank + 1 `rank` from
(select distinct(score) from Scores order by score desc) s1 join (select @rank := 0) s2) s3
on Scores.score = s3.score
order by `rank`;