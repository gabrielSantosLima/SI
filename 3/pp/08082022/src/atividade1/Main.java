package atividade1;

public class Main {
	Departamento d = new Departamento("DAIC");
	Funcionario f = new Funcionario("Gabriel", 19, "a@gmail.com", d);
	d.addFuncionario(f);
}
