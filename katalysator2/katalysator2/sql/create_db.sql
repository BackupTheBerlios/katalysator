CREATE SEQUENCE S_Projekt;

CREATE TABLE T_Projekt(
	id int8 DEFAULT nextval('s_projekt'),
	Bezeichnung varchar(40) UNIQUE,
	Beschreibung text,
	Anfang date,
	Ende date,
	CHECK(Anfang<Ende),
	PRIMARY KEY (id)
);

CREATE SEQUENCE S_Sub_Projekt;

CREATE TABLE T_Sub_Projekt(
	id int8 DEFAULT nextval('S_Sub_Projekt'),
	Projekt int8 REFERENCES T_Projekt(id),
	Bezeichnung varchar(40) UNIQUE,
	Beschreibung text,
	PRIMARY KEY(id)
);

CREATE SEQUENCE S_Anlage;

CREATE TABLE T_Anlage(
	id int8 DEFAULT nextval('S_Anlage'),
	sub_projekt int8 REFERENCES T_Sub_Projekt(id),
	Bezeichnung varchar(40) UNIQUE,
	Beschreibung  text,
	PRIMARY KEY(id)
);

CREATE SEQUENCE S_Material;

CREATE TABLE T_Material(
	id int8 DEFAULT nextval('S_Material') PRIMARY KEY,
	Bezeichnung varchar(100) UNIQUE,
	Beschreibung text
);

CREATE SEQUENCE S_SI_Einheit;

CREATE TABLE T_SI_Einheit(
	id int8 DEFAULT nextval('S_SI_Einheit') PRIMARY KEY,
	Bezeichnung varchar(100) UNIQUE,
	Beschreibung text
);

CREATE SEQUENCE S_Einheit;

CREATE TABLE T_Einheit(
	id int8 DEFAULT nextval('S_Einheit') PRIMARY KEY,
	SI_Einheit int8 REFERENCES T_SI_Einheit(id),
	Bezeichnung varchar(40),
	Faktor float4,
	UNIQUE(SI_Einheit, Faktor)
);



CREATE SEQUENCE S_Phys_Merkmal;

CREATE TABLE T_Phys_Merkmal(
	id int8 DEFAULT nextval('S_Phys_Merkmal') PRIMARY KEY,
	Einheit int8 REFERENCES T_Einheit(id),
	Bezeichnung varchar(100) UNIQUE,
	Beschreibung text
);

CREATE SEQUENCE S_Material_Daten;

CREATE TABLE T_Material_Daten(
	id int8 DEFAULT nextval('S_Material_Daten') PRIMARY KEY,
	Material int8 REFERENCES T_Material(id),
	Phys_Merkmal int8 REFERENCES T_Phys_Merkmal(id),
	Wert float4
);


CREATE SEQUENCE S_Beladung;

CREATE TABLE T_Beladung(
	id int8 DEFAULT nextval('S_Beladung') PRIMARY KEY,
	bezeichnung varchar(100),
	nummer int2
);

CREATE SEQUENCE S_Beladung_Merkmal;

CREATE TABLE T_Beladung_Merkmal(
	id int8 DEFAULT nextval('S_Beladung_Merkmal') PRIMARY KEY,
	bezeichnung varchar(100),
	beschreibung text,
	Einheit int8 REFERENCES T_Einheit(id)
);

CREATE SEQUENCE S_Beladung_Daten;

CREATE TABLE T_Beladung_Daten(
	id int8 DEFAULT nextval('S_Beladung_Daten') PRIMARY KEY,
	Beladung_Merkmal int8 REFERENCES T_Beladung_Merkmal,
	Beladung int8 REFERENCES T_Beladung(id),
	Wert float4
);

CREATE SEQUENCE S_Beschichtung;

CREATE TABLE T_Beschichtung(
	id int8 DEFAULT nextval('S_Beschichtung') PRIMARY KEY,
	Bezeichnung varchar(100),
	Hersteller varchar(100),
	LosNr varchar(100),
	UNIQUE (Bezeichnung, Hersteller, LosNr)
);

CREATE SEQUENCE S_Bauteil_Typ;

CREATE TABLE T_Bauteil_Typ(
	id int8 DEFAULT nextval('S_Bauteil_Typ') PRIMARY KEY,
	Bezeichnung varchar(100) UNIQUE,
	Beschreibung text
);

CREATE SEQUENCE S_Bauteil_Merkmal;

CREATE TABLE T_Bauteil_Merkmal(
	id int8 DEFAULT nextval('S_Bauteil_Merkmal') PRIMARY KEY,
	Bauteil_Typ int8 REFERENCES T_Bauteil_Typ(id),
	Phys_Merkmal int8 REFERENCES T_Phys_Merkmal(id),
	UNIQUE (Bauteil_Typ, Phys_Merkmal)
);

CREATE SEQUENCE S_Bauteil;

CREATE TABLE T_Bauteil(
	id int8 DEFAULT nextval('S_Bauteil') PRIMARY KEY,
	Bezeichnung varchar(100),
	Beschreibung text,
	Anlage int8 REFERENCES T_Anlage(id),
	Bauteil_Typ int8 REFERENCES T_Bauteil_Typ(id),
	Beschichtung int8 REFERENCES T_Beschichtung(id)
);

CREATE SEQUENCE S_Bauteil_Material;

CREATE TABLE T_Bauteil_Material(
	id int8 DEFAULT nextval('S_Bauteil_Material') PRIMARY KEY,
	Bauteil int8 REFERENCES T_Bauteil(id),
	Material int8 REFERENCES T_Material(id),
	Bezeichnung varchar(100)
);

CREATE SEQUENCE S_Bauteil_Wert;

CREATE TABLE T_Bauteil_Wert(
	id int8 DEFAULT nextval('S_Bauteil_Wert') PRIMARY KEY,
	Bauteil int8 REFERENCES T_Bauteil(id),
	Bauteil_Merkmal int8 REFERENCES T_Bauteil_Merkmal(id),
	Wert float4
);

CREATE SEQUENCE S_Verknuepfung_Merkmal;

CREATE TABLE T_Verknuepfung_Merkmal(
	id int8 DEFAULT nextval('S_Verknuepfung_Merkmal') PRIMARY KEY,
	Bezeichnung varchar(100),
	Beschreibung text
);

CREATE SEQUENCE S_Verknuepfung;

CREATE TABLE T_Verknuepfung(
	id int8 DEFAULT nextval('S_Verknuepfung') PRIMARY KEY,
	Anfang int8 REFERENCES T_Bauteil(id),
	Ende int8 REFERENCES T_Bauteil(id),
	Merkmal int8 REFERENCES T_Verknuepfung_Merkmal(id),
	Bezeichnung varchar(100)
);

CREATE SEQUENCE S_Temp_Messtellen;

CREATE TABLE T_Temp_Messtellen(
	id int8 DEFAULT nextval('S_Temp_Messtellen') PRIMARY KEY,
	Bauteil int8 REFERENCES T_Bauteil(id),
	Bezeichnung varchar(40),
	Beschreibung text,
	Durchmesser float4,
	TE_Typ varchar(100),
	axial float4,
	radial float4,
	winkel float4,
	UNIQUE(axial, radial, winkel, TE_Typ, Durchmesser, Bauteil)
);

CREATE SEQUENCE S_Hersteller;

CREATE TABLE T_Hersteller(
	id int8 DEFAULT nextval('S_Hersteller') PRIMARY KEY,
	name varchar(40),
	land varchar(40),
	Bemerkung text,
	UNIQUE(name,land)
);

CREATE SEQUENCE S_Kraftstoff;

CREATE TABLE T_Kraftstoff(
	id int8 DEFAULT nextval('S_Kraftstoff') PRIMARY KEY,
	name varchar(40),
	octanzahl float4,
	Bemerkung text
);

CREATE SEQUENCE S_Motor;

CREATE TABLE T_Motor(
	id int8 DEFAULT nextval('S_Motor') PRIMARY KEY,
	hersteller int8 REFERENCES T_Hersteller(id),
	Kraftstoff int8 REFERENCES T_Kraftstoff(id),
	Hubraum float4,
	Turbo bool,
	Bezeichnung varchar(40),
	Beschreibung text,
	gebaut date
);

CREATE SEQUENCE S_Labor;

CREATE TABLE T_Labor(
	id int8 DEFAULT nextval('S_Labor') PRIMARY KEY,
	Bezeichnung varchar(100),
	Ort varchar(100),
	Beschreibung text
);

CREATE SEQUENCE S_Messzyklus;

CREATE TABLE T_Messzyklus(
	id int8 DEFAULT nextval('S_Messzyklus') PRIMARY KEY,
	Bezeichnung varchar(100),
	Beschreibung text
);

CREATE SEQUENCE S_Messung;

CREATE TABLE T_Messung(
	id int8 DEFAULT nextval('S_Messung') PRIMARY KEY,
	Sub_Projekt int8 REFERENCES T_Sub_Projekt(id),
	Motor int8 REFERENCES T_Motor(id),
	Anlage int8 REFERENCES T_Anlage(id),
	Labor int8 REFERENCES T_Labor(id),
	Durchfuehrender varchar(100),
	Messzyklus int8 REFERENCES T_Messzyklus(id),
	Bemerkung text,
	Datum date
);

CREATE SEQUENCE S_Zeit;

CREATE TABLE T_Zeit(
	id int8 DEFAULT nextval('S_Zeit') PRIMARY KEY,
	messung int8 REFERENCES T_Messung(id),
	Zeit float8
);

CREATE SEQUENCE S_Temperaturen;

CREATE TABLE T_Temperaturen_modal(
	id int8 DEFAULT nextval('S_Temperaturen_Modal') PRIMARY KEY,
	Zeit int8 REFERENCES T_Zeit(id),
	Messtelle int8 REFERENCES T_Temp_Messtellen(id),
	Temperatur float8,
	UNIQUE (Messtelle, Zeit)
);

CREATE SEQUENCE S_sonst_Merkmal;

CREATE TABLE T_sonst_Merkmal(
	id int8 DEFAULT nextval('S_sonst_Merkmal') PRIMARY KEY,
	Einheit int8 REFERENCES T_Einheit(id),
	Bezeichnung varchar(100),
	Beschreibung text
);

CREATE SEQUENCE S_sonst_Werte;

CREATE TABLE T_sonst_Werte(
	id int8 DEFAULT nextval('S_sonst_Werte') PRIMARY KEY,
	Zeit int8 REFERENCES T_Zeit(id),
	Merkmal int8 REFERENCES T_sonst_Merkmal(id),
	Wert float4
);

CREATE SEQUENCE S_Q_Merkmal;

CREATE TABLE T_Q_Merkmal(
	id int8 DEFAULT nextval('S_Q_Merkmal') PRIMARY KEY,
	Einheit int8 REFERENCES T_Einheit(id),
	Bezeichnung varchar(100),
	Beschreibung text
);

CREATE SEQUENCE S_Q_Messtellen;

CREATE TABLE T_Q_Messtellen(
	id int8 DEFAULT nextval('S_Q_Messtellen') PRIMARY KEY,
	Bauteil int8 REFERENCES T_Bauteil(id),
	Merkmal int8 REFERENCES T_Q_Merkmal(id),
	Bezeichnung varchar(100),
	Beschreibung text
);

CREATE SEQUENCE S_Q_Werte;

CREATE TABLE T_Q_Werte(
	id int8 DEFAULT nextval('S_Q_Werte') PRIMARY KEY,
	Zeit int8 REFERENCES T_Zeit(id),
	Messtelle int8 REFERENCES T_Q_Messtellen(id),
	Wert float4
);

CREATE SEQUENCE S_CVS_Merkmal;

CREATE TABLE T_CVS_Merkmal(
	id int8 DEFAULT nextval('S_CVS_Merkmal') PRIMARY KEY,
	Bezeichnung varchar(40) UNIQUE
);

CREATE SEQUENCE S_CVS;

CREATE TABLE T_CVS(
	id int8 DEFAULT nextval('S_CVS') PRIMARY KEY,
	Messung int8 REFERENCES T_MESSUNG(id),
	CVS_Merkmal int8 REFERENCES T_CVS_Merkmal(id),
	Merkmal int8 REFERENCES T_CVS_Merkmal(id),
	Q_Merkmal int8 REFERENCES T_Q_Merkmal(id),
	Wert float4
);
