-- Write your query below
-- WITH No_CRIMSON AS (
--     SELECT
--         sales_id
--     FROM
--         orders o
--     JOIN    
--         company c
--         ON
--             o.com_id = c.com_id
--     WHERE
--         c.name = 'CRIMSON'
-- )
SELECT
    sp.name
FROM
    sales_person sp
WHERE
    sp.sales_id NOT IN (
        SELECT
            sales_id
        FROM
            orders o
        JOIN    
            company c
            ON
                o.com_id = c.com_id
        WHERE
            c.name = 'CRIMSON'
    );