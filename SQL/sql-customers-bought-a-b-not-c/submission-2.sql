-- Write your query below
SELECT
    c.customer_id,
    c.customer_name
FROM
    customers c
WHERE
    'C' NOT IN (
        SELECT
            product_name
        FROM
            orders o
        WHERE 
            o.customer_id = c.customer_id
            -- AND product_name IS NOT NULL
    ) AND 'A' IN (
        SELECT
            product_name
        FROM
            orders o
        WHERE 
            o.customer_id = c.customer_id
    ) AND 'B' IN (
        SELECT
            product_name
        FROM
            orders o
        WHERE 
            o.customer_id = c.customer_id
    )
ORDER BY 
    c.customer_name;