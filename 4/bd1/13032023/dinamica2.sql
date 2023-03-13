-- Active: 1678731789179@@127.0.0.1@3306
-- a) Nome e matrícula de todos os alunos com idade maior que 24
SELECT nome_aluno, matricula 
FROM "Aluno" 
WHERE idade > 24;

-- b) Nome e idade de todos os alunos dos cursos de 
-- "Tec Anal Des Sistema" e "Educação Física"
SELECT nome_aluno, idade
FROM "Aluno" as a
INNER JOIN "Curso" as c
ON a.id_curso = c.id_curso
WHERE c.nome_curso IN ('TADS', 'EDF')   

-- e) Histórico que os professores Manoel, Cristiano, 
-- Rafael participaram
SELECT h.ano, h.periodo, d.nome_disciplina, c.nome_curso
FROM "Historico" as h
INNER JOIN "Disciplina" as d
ON h.id_disciplina = d.id_disciplina 
INNER JOIN "Curso" as c
ON h.id_curso = c.id_curso
WHERE h.id_professor IN (1000, 1002, 1003);

-- f) Histórico que os professores Manoel, Cristiano, 
-- Rafael não participaram
SELECT h.ano, h.periodo, d.nome_disciplina, c.nome_curso
FROM "Historico" as h
INNER JOIN "Disciplina" as d
ON h.id_disciplina = d.id_disciplina 
INNER JOIN "Curso" as c
ON h.id_curso = c.id_curso
WHERE h.id_professor NOT IN (1000, 1002, 1003);


-- g) Alunos com número de matrícula

SELECT * FROM "Aluno"
WHERE matricula IS NOT NULL;

-- h) Alunos com número de matrícula

SELECT * FROM "Aluno"
WHERE matricula IS NULL;

-- i) Alunos com idade entre 20 e 29 anos

SELECT * 
FROM "Aluno"
WHERE idade BETWEEN 20 and 29;

-- j) Disciplinas que terminem com a letra 's'

SELECT * 
FROM "Disciplina"
WHERE nome_disciplina LIKE '%s';

-- l) Soma das idades dos alunos por curso
SELECT c.nome_curso, SUM(idade) as 'soma de idades'
FROM "Aluno" as a
INNER JOIN "Curso" as c
ON a.id_curso = c.id_curso
GROUP BY c.nome_curso;

-- m) Soma das idades dos alunos por curso superiores a 40
SELECT c.nome_curso, SUM(a.idade) as 'idades'
FROM "Aluno" as a
INNER JOIN "Curso" as c
ON a.id_curso = c.id_curso
GROUP BY c.nome_curso
HAVING SUM(idade) > 40;