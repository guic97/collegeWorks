/* Iniciando */
create database atividade1;
use atividade1;

/* Criação de tabelas */

create table diretor
(
	idDiretor int not null primary key,
	nome varchar(45) not null
);

create table genero
(
	idGenero int not null primary key,
	nome varchar(45) not null
);

create table filme_has_premiacao 
(
	idFilmePremiacao int not null primary key,
    premiacaoIdPremiacao int not null,
    ganhou bool not null
);

create table premiacao 
(
	idPremiacao int not null primary key,
    nome varchar(45) not null,
    ano date not null
);

create table filme_exibido_sala 
(
	idFilmeExibidoSala int not null primary key,
    salaIdSala int not null,
    horarioIdHorario int not null
);

create table sala 
(
	idSala int not null primary key,
    nome varchar(45) not null,
    capacidade int not null
);

create table horario 
(
	idHorario int not null primary key,
    horario time not null
);
create table funcionario 
(
	idFuncionario int not null primary key,
    nome varchar(45) not null,
    carteiraTrabalho int not null,
    dataContratacao date not null,
    salario float not null
);

create table funcao 
(
	idFuncao int not null primary key,
    nome varchar(45) not null
);

CREATE TABLE horario_trabalho_funcionario (
    idHorarioTrabalho INT NOT NULL PRIMARY KEY,
    funcionarioIdFuncionario INT NOT NULL,
	funcao_idfuncao int not null,
    constraint funcao_idfuncao 
		foreign key (funcao_idfuncao)
		references funcao(idFuncao)
);
create table filme
(
	idFilme int not null primary key,
    nomeBR varchar (45) not null,
    nomeEN varchar (45) not null,
    anoLancamento date not null,
    sinopse text not null,
    
    diretor_idDiretor int not null,
    constraint diretor_idDiretor 
		foreign key (diretor_idDiretor)
		references diretor(idDiretor),
        
	genero_idgenero int not null,
    constraint genero_idgenero 
		foreign key (genero_idgenero)
		references genero(idGenero)
);

/* Códigos de teste */
describe filme;
show tables;
drop database atividade1;