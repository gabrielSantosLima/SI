package atividade1;

public class DepartamentoFuncionario {
	private Funcionario funcionario;
	private Departamento departamento;
	
	public DepartamentoFuncionario(Funcionario funcionario, Departamento departamento) {
		this.setFuncionario(funcionario);
		this.setDepartamento(departamento);
	}
	
	public void setDepartamento(Departamento departamento) {
		this.departamento = departamento;
	}
	
	public void setFuncionario(Funcionario funcionario) {
		this.funcionario = funcionario;
	}
	
	public Departamento getDepartamento() {
		return departamento;
	}
	
	public Funcionario getFuncionario() {
		return funcionario;
	}
}
