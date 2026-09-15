-- Write your query below
SELECT
    left_operand,
    operator,
    right_operand,
    CASE 
        WHEN operator = '=' AND v1.value = v2.value THEN 'true'
        WHEN operator = '<' AND v1.value < v2.value THEN 'true'
        WHEN operator = '>' AND v1.value > v2.value THEN 'true'
        ELSE 'false'
    END AS "value"
FROM
    expressions e
JOIN
    variables v1
    ON
        left_operand = v1.name
JOIN
    variables v2
    ON
        right_operand = v2.name
