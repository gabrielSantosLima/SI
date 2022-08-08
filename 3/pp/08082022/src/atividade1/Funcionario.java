package atividade1;

import java.util.ArrayList;
import java.util.List;

public class Funcionario {
	private String nome;
	private int idade;
	private String email;
	private List<DepartamentoFuncionario> departamentoFuncionarios;

	
	public Funcionario(String nome, int idade, String email, Departamento departamento){
		this.setNome(nome);
		this.setIdade(idade);
		this.setEmail(email);
		this.setDepartamentoFuncionarios(new ArrayList<>());
		this.addDepartamento(new DepartamentoFuncionario(this, departamento));			
	}
	
	public List<DepartamentoFuncionario> getDepartamentoFuncionarios() {
		return departamentoFuncionarios;
	}
	
	public void setDepartamentoFuncionarios(List<DepartamentoFuncionario> departamentoFuncionarios) {
		this.departamentoFuncionarios = departamentoFuncionarios;
	}
	
	public void addDepartamento(DepartamentoFuncionario departamentoFuncionario) {
		getDepartamentoFuncionarios().add(departamentoFuncionario);
	}
	
	public void setEmail(String email) {
		this.email = email;
	}
	
	public void setIdade(int idade) {
		this.idade = idade;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getEmail() {
		return email;
	}
	
	public int getIdade() {
		return idade;
	}
	
	public String getNome() {
		return nome;
	}
}
