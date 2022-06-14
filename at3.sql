create database at3;
use at3;

create table instrutor(
	idInstrutor int not null primary key,
    rgInstrutor int not null,
    nome varchar(45) not null,
    nascimento date,
    titulacao int
);

create table telefone_instrutor(
	idTelefone int not null primary key,
    numero int not null,
    tipo varchar(45),
    instrutor_idInstrutor int not null,
		constraint instrutor_idInstrutor
			foreign key (instrutor_idInstrutor)
			references instrutor(idInstrutor)
);

create table atividade(
	idAtividade int not null primary key,
    nome varchar(100) not null
);

create table turma(
	idTurma int not null primary key,
    horario time not null,
    duracao int not null,
    dataInicio date not null,
    dataFim date not null,
    atividade_idAtividade int not null,
		constraint atividade_idAtividade
			foreign key (atividade_idAtividade)
            references atividade(idAtividade),
    
    instrutor_idInstrutor int not null,
		constraint instrutor_idInstrutor2
			foreign key (instrutor_idInstrutor)
            references instrutor(idInstrutor)
);

create table aluno(
	codMatricula int not null primary key,
    turma_idTurma int,
		constraint turma_idTurma
			foreign key (turma_idTurma)
            references turma(idTurma),
    
    dataMatricula date not null,
    nome varchar(45) not null,
    endereco text,
    telefone int,
    dataNacimento date,
    altura float,
    peso int
);

create table matricula(
	aluno_codMatricula int not null,
	turma_idTurma int not null,
    constraint pk_matricula_turma primary key (aluno_codMatricula, turma_idTurma),
    
	constraint fk_aluno_codMatricula foreign key (aluno_codMatricula) references aluno(codMatricula),
	constraint fk_turma_idTurma foreign key (turma_idTurma) references turma(idTurma)
);

create table chamada(
	idChamada int not null primary key,
    dataChamada date not null,
    presente bool not null,
    matricula_aluno_codMatricula int not null,
		constraint matricula_aluno_codMatricula foreign key (matricula_aluno_codMatricula) references matricula(aluno_codMatricula),
    matricula_turma_idTurma int not null,
		constraint matricula_turma_idTurma foreign key (matricula_turma_idTurma) references matricula(turma_idTurma)
);

select * from turma;