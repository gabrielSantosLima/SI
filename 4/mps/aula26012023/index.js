const cycles = 25;

const disciplines = [
  "Aula de MPS",
  "Aula de PLP",
  "Aula de AED2",
  "Aula de ED2",
  "Aula de BD1",
  "Aula de RC1",
];

function getRandomInt(min, max) {
  min = Math.ceil(min);
  max = Math.floor(max);
  return Math.floor(Math.random() * (max - min) + min);
}

function getRandomDisciplines() {
  const length = disciplines.length;
  const index = getRandomInt(0, length);
  return disciplines[index];
}

let query = "INSERT INTO agenda_eventos VALUES";

for (let index = 0; index < cycles; index++) {
  query += `\n(NULL, '${getRandomDisciplines()}', '2023-01-23 10:00:56', 'Uma aula massa!', 0, ${getRandomInt(
    3,
    8
  )})`;
  if (index !== cycles - 1) query += ",";
}
query += ";";
console.log(query);
