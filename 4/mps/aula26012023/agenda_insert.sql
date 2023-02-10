INSERT INTO agenda_usuario VALUES
	(NULL, 'Gabriel Lima', 'lima.gabrieldsantos@gmail.com', 0),
    (NULL, 'Guilherme Lima', 'gui@gmail.com', 0),
    (NULL, 'Arthur Lima', 'arhur@gmail.com', 0),
    (NULL, 'Julia Lima', 'ju@gmail.com', 0),
    (NULL, 'Maria DB', 'maria@gmail.com', 0);

SELECT * FROM agenda_usuario;

INSERT INTO agenda_eventos VALUES
(NULL, 'Aula de RC1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 6),
(NULL, 'Aula de RC1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 5),
(NULL, 'Aula de MPS', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 6),
(NULL, 'Aula de ED2', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 3),
(NULL, 'Aula de PLP', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 5),
(NULL, 'Aula de RC1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 5),
(NULL, 'Aula de ED2', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 3),
(NULL, 'Aula de BD1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 4),
(NULL, 'Aula de ED2', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 4),
(NULL, 'Aula de BD1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 4),
(NULL, 'Aula de PLP', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 4),
(NULL, 'Aula de PLP', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 3),
(NULL, 'Aula de RC1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 3),
(NULL, 'Aula de PLP', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 7),
(NULL, 'Aula de BD1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 3),
(NULL, 'Aula de BD1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 7),
(NULL, 'Aula de ED2', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 5),
(NULL, 'Aula de RC1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 3),
(NULL, 'Aula de PLP', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 5),
(NULL, 'Aula de RC1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 4),
(NULL, 'Aula de MPS', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 5),
(NULL, 'Aula de BD1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 3),
(NULL, 'Aula de RC1', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 6),
(NULL, 'Aula de ED2', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 7),
(NULL, 'Aula de MPS', '2023-01-23 10:00:56', 'Uma aula massa!', 0, 4);

SELECT * FROM agenda_eventos;

SELECT e.*, u.usuario_nome as "Dono do evento"
FROM agenda_usuario as u, agenda_eventos as e
WHERE e.usuario_id = u.usuario_id
ORDER BY u.usuario_nome;