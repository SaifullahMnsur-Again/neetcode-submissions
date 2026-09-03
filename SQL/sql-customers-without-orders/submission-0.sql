-- Write your query below
SELECT
    name
FROM
    customers c
LEFT JOIN
    orders o
    ON o.customer_id = c.id
WHERE
    o.id IS NULL;