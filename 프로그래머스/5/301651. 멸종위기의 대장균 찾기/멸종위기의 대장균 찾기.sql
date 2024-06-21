WITH RECURSIVE Generations AS (
    -- 최초 세대 (Generation 1)
    SELECT 
        ID,
        1 AS GENERATION
    FROM 
        ECOLI_DATA
    WHERE 
        PARENT_ID IS NULL

    UNION ALL

    -- 이후 세대들
    SELECT 
        e.ID,
        g.GENERATION + 1
    FROM 
        ECOLI_DATA e
    INNER JOIN 
        Generations g ON e.PARENT_ID = g.ID
)
, LeafNodes AS (
    -- 자식이 없는 개체 찾기
    SELECT 
        g.ID,
        g.GENERATION
    FROM 
        Generations g
    LEFT JOIN 
        ECOLI_DATA e ON g.ID = e.PARENT_ID
    WHERE 
        e.ID IS NULL
)
-- 세대별 자식이 없는 개체 수 세기
SELECT 
    COUNT(*) AS COUNT,
    GENERATION
FROM 
    LeafNodes
GROUP BY 
    GENERATION
ORDER BY 
    GENERATION;
