create table songs (
    id      NUMBER(5) PRIMARY KEY,
    title   VARCHAR2(40) NOT NULL,
    artist  VARCHAR2(40) NOT NULL,
    album   VARCHAR2(40) NOT NULL,
    lyrics  VARCHAR2(10),
    top_id  NUMBER(5)
)

create table users (
    id      NUMBER(5) PRIMARY KEY,
    usrname VARCHAR2(15) NOT NULL,
    pwd     VARCHAR2(20) NOT NULL,
    alias   VARCHAR2(15)
)

create table leaderboards (
    id      NUMBER(5) PRIMARY KEY,
    song_id NUMBER(5) NOT NULL,
    points  NUMBER(5) NOT NULL,
    usr_id  NUMBER(5) NOT NULL,
    s_date    DATE
)


insert into songs (
    id, title, artist, album, lyrics, top_id )
values (
    1, 'Knee Socks', 'Arctic Monkeys', 'AM', 'tba', NULL )
    
insert into songs (
    id, title, artist, album, lyrics, top_id )
values (
    2, 'Laughing Gas', 'The Fratellis', 'In Your Own Sweet Time', 'tba', NULL )

insert into users (
    id, usrname, pwd, alias )
values (
    1, 'usr1', 'pw1', 'Jani' )

insert into users (
    id, usrname, pwd, alias )
values (
    2, 'usr2', 'pw2', 'Dani' )
    
insert into leaderboards (
    id, song_id, points, usr_id, s_date )
values (
    1, 1, 23, 2, null )
    
insert into leaderboards (
    id, song_id, points, usr_id, s_date )
values (
    2, 2, 35, 1, null )
    
select * from songs;
select * from users;
select * from leaderboards;