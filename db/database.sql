-- DB

-- Ingresar a la db
sudo -u postgres psql

-- Actualizamos el usuario postgres
ALTER user postgres WITH PASSWORD 'adrianshow1927';

-- Creamos la database
CREATE DATABASE PROYECTO;

-- Creamos la tabla
CREATE TABLE datos (
    id SERIAL PRIMARY KEY,
    idNodo VARCHAR(100),
    nivelSonoro VARCHAR(50),
    alerta VARCHAR(100),
    fechaHora TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE atencion (
    id SERIAL PRIMARY KEY,
    direccion VARCHAR(100),
    nombre VARCHAR(100),
    alerta VARCHAR(3),
    fechaHora TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

-- Datos
INSERT INTO datos (idNodo, nivelSonoro, alerta) VALUES ('Calle siempre viva', 2.2, 'Nivel de ruido normal');
INSERT INTO atencion (direccion, nombre, alerta) VALUES ('Calle siempre viva', 'Camilo Farina', 'No');
-- DB

-- Ingresar a la db
sudo -u postgres psql

-- Actualizamos el usuario postgres
ALTER user postgres WITH PASSWORD 'adrianshow1927';

-- Creamos la database
CREATE DATABASE PROYECTO;

-- Creamos la tabla
CREATE TABLE datos (
    id SERIAL PRIMARY KEY,
    idNodo VARCHAR(100),
    nivelSonoro VARCHAR(50),
    alerta VARCHAR(100),
    fechaHora TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE atencion (
    id SERIAL PRIMARY KEY,
    direccion VARCHAR(100),
    nombre VARCHAR(100),
    alarma VARCHAR(3),
    fechaHora TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
);

-- Datos
INSERT INTO datos (idNodo, nivelSonoro, alerta) VALUES ('Calle siempre viva', 2.2, 'Nivel de ruido normal');
INSERT INTO atencion (direccion, nombre, alerta) VALUES ('Calle siempre viva', 'Camilo Farina', 'No');