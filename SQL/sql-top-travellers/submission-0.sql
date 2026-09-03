-- Write your query below
SELECT
    name,
    CASE
        WHEN
            SUM(distance) IS NOT NULL THEN SUM(distance)
        ELSE
            0
    END AS travelled_distance
FROM 
    users u
LEFT JOIN
    rides r
    ON 
        r.user_id = u.id
GROUP BY
    u.id
ORDER BY
    travelled_distance DESC,
    name ASC;