-- Write your query below
WITH Ranked_Table AS (
    SELECT
        student_id,
        exam_id,
        score,
        DENSE_RANK() OVER (PARTITION BY student_id ORDER BY score DESC, exam_id ASC) as mark_rank
    FROM
        exam_results
)

SELECT
    student_id,
    exam_id,
    score
FROM
    Ranked_Table
WHERE
    mark_rank = 1;