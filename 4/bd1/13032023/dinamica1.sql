-- Active: 1678731789179@@127.0.0.1@3306
-- a) Alterar descrição do curso EDF para Educação Física e Fisioterapia
UPDATE "Curso"
SET descricao = "Educação Física e Fisioterapia"
WHERE nome_curso LIKE "%EDF%";

SELECT * FROM "Curso";

-- b) Deletar disciplinas
SELECT * FROM "Disciplina";
DELETE FROM "Disciplina"
WHERE nome_disciplina LIKE "GEN" 
OR nome_disciplina LIKE "CAL"
OR nome_disciplina LIKE "TE";
