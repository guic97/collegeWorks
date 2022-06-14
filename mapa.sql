create database mapaBd2;
use mapaBd2;

create table paciente (
	cpf bigint not null primary key,
    nome varchar(45) not null,
    genero enum("m","f","o") not null
);

create table profissionalSaude (
	id_registro bigint not null primary key,
    nome varchar(50) not null,
    especialidade varchar(50) not null,
    edicao bool not null
);

create table clinica (
	id_registro_clinica bigint not null primary key,
    nome_registro varchar(50) not null,
    nome_fantasia varchar(50) not null
);

create table contato (
	cpf_paciente bigint,
    constraint tipoContato_cpf_paciente
        foreign key (cpf_paciente)
        references paciente(cpf),
    registro_profissional bigint,
     constraint tipoContato_registro_profissional
        foreign key (registro_profissional)
        references profissionalSaude(id_registro),
	registro_clinica bigint,
     constraint tipoContato_registro_clinica
        foreign key (registro_clinica)
        references clinica(id_registro_clinica),
    descricao_contato varchar(50) not null,
    max_por_pessoa tinyint not null,
    contato varchar(50) not null
);

create table endereco (
	cpf_paciente bigint,
    constraint endereco_cpf_paciente
        foreign key (cpf_paciente)
        references paciente(cpf),
    registro_profissional bigint,
     constraint endereco_registro_profissional
        foreign key (registro_profissional)
        references profissionalSaude(id_registro),
	registro_clinica bigint,
     constraint endereco_registro_clinica
        foreign key (registro_clinica)
        references clinica(id_registro_clinica),
    pais varchar(50) not null,
    estado varchar(50) not null,
    cidade varchar(50) not null,
    rua varchar(100) not null,
    numero_casa int not null,
    complemento varchar(50),
    cep bigint
);

create table laudo (
	id_laudo bigint not null primary key,
    data_laudo date not null,
    local_laudo varchar(50) not null,
    obs text,
    orientacoes text,
    qtd_laudo tinyint not null,
    valor_laudo float not null,
    cpf_paciente bigint,
    constraint laudo_cpf_paciente
        foreign key (cpf_paciente)
        references paciente(cpf)
);

create table exame (
	id_exame bigint not null primary key,
    data_exame date not null,
    tipo_exame varchar(50) not null,
    obs text,
    nome_paciente varchar(50) not null,
    cpf_paciente bigint not null,
		constraint exame_cpf_paciente
        foreign key (cpf_paciente)
        references paciente(cpf)
);

create table tipoExame (
	id_tipo_exame int not null primary key,
    descricao varchar(50) not null,
	valor_exame float not null,
    id_exame bigint not null,
		constraint tipo_id_exame
		foreign key (id_exame)
		references exame(id_exame)
);

create table precoExame (
	id_preco int not null primary key,
    inicio_valor date not null,
    validade_valor date not null,
    preco float not null,
    id_tipo int not null,
		constraint precoExame_preco_tipo
        foreign key (id_tipo)
        references tipoExame(id_tipo_exame)
);


describe paciente;
select * from en;
drop database mapabd2;