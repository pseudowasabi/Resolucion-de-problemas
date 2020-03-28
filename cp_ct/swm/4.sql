SELECT STAGE, ROUND(AVG(STUDENT_NUM), 0) AS AVG_STUDENT_NUM, ROUND(SUM(STUDENT_NUM)/SUM(TEACHER_NUM), 1) AS STUDENT_NUM_PER_TEACHER FROM SCHOOLS GROUP BY STAGE ORDER BY AVG_STUDENT_NUM DESC, STUDENT_NUM_PER_TEACHER ASC;