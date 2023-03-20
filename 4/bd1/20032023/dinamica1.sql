-- Active: 1679335867258@@127.0.0.1@3306
-- 1) Mostrar o nome de todos cursos do departamento "C humanas"
SELECT C.nome_curso 
FROM "Departamento" as D 
INNER JOIN "Curso" as C
ON C.id_depto = D.id_depto
WHERE D.nome_depto LIKE 'C humanas';

-- 2) Mostrar todas as informações de alunos matriculados 
-- no curso "C exatas"
SELECT A.*, C.nome_curso
FROM "Aluno" as A
INNER JOIN "Curso" as C
ON A.id_curso = C.id_curso
INNER JOIN "Departamento" as D
ON D.id_depto = C.id_depto
WHERE D.nome_depto = 'C exatas';

-- 3) Mostre o nome de todas as disciplinas e o nome dos cursos
-- das disciplinas que o professor "Cristiano" ministrou 
SELECT D.nome_disciplina, C.nome_curso
FROM "Historico" as H
INNER JOIN "Disciplina" as D
ON H.id_disciplina = D.id_disciplina
INNER JOIN "Curso" as C
ON H.id_curso = C.id_curso
INNER JOIN "Professor" as P
ON H.id_professor = P.id_professor
WHERE P.nome_professor LIKE 'Cristiano';