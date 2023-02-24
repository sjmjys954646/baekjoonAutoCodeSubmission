-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, left(DATE_OF_BIRTH, 10) AS DATE_OF_BIRTH 
FROM MEMBER_PROFILE 
WHERE TLNO is not null and substr(DATE_OF_BIRTH, 7, 1) = 3  and GENDER = 'W'
order by member_id 