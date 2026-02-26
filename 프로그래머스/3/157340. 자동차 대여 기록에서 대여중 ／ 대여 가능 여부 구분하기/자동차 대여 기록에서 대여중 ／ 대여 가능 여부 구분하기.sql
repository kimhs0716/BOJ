SELECT 
    CAR_ID, 
    CASE
        WHEN 
            EXISTS (
                SELECT 1
                FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY Y
                WHERE X.CAR_ID = Y.CAR_ID AND
                    '2022-10-16' BETWEEN START_DATE AND END_DATE
            )
        THEN '대여중'
        ELSE '대여 가능'
    END AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY X
GROUP BY CAR_ID
ORDER BY CAR_ID DESC;