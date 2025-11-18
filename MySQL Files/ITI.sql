DROP DATABASE IF EXISTS iti_first_proj;

CREATE DATABASE iti_first_proj;
USE iti_first_proj;

CREATE TABLE students (
    student_id INT AUTO_INCREMENT,
    name VARCHAR(255),
    age INT,
    department VARCHAR(255),
    gpa DECIMAL(10,9),
    CONSTRAINT pk_students PRIMARY KEY(student_id)
);

INSERT INTO students
VALUES(1,"First Student", 22, "AI", 3.97);

SELECT * FROM students;

SHOW COLUMNS FROM students;

INSERT INTO students(name, age, department, gpa)
VALUES("Second Student", 23, "DS", 3.55);
