package atividade1;

import java.util.ArrayList;
import java.util.List;

public class Departamento {
	private String nome;
	private List<DepartamentoFuncionario> departamentoFuncionarios;
	
	public Departamento(String nome) {
		this.setNome(nome);
		this.setDepartamentoFuncionarios(new ArrayList<>());
	}
	
	public List<DepartamentoFuncionario> getDepartamentoFuncionarios() {
		return departamentoFuncionarios;
	}
	
	public void setDepartamentoFuncionarios(List<DepartamentoFuncionario> departamentoFuncionarios) {
		this.departamentoFuncionarios = departamentoFuncionarios;
	}
	
	public void addFuncionario(Funcionario funcionario) {
		getDepartamentoFuncionarios().add(new DepartamentoFuncionario(funcionario, this));
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
}
