INSERT INTO agenda_usuario VALUES(NULL, 'Gabriel Doido', 'lima.gabrieldsantos@gmail.com', 0), (NULL, 'Melinne', 'melinne@gmail.com', 0);

SELECT * FROM agenda_usuario;

UPDATE agenda_usuario
SET usuario_nome = 'Gabriel Lima'
WHERE usuario_id = 1;

DELETE FROM agenda_usuario WHERE usuario_id = 1;
