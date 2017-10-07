-- mariadb sql
use test;

CREATE TABLE IF NOT EXISTS `admin`( `id` int(6) unsigned NOT NULL 
auto_increment, `username` varchar(50) NOT NULL default '', `password` 
varchar(100) default NULL, primary key(id) ) engine=myisam default 
charset=utf8 auto_increment=2;
insert into admin(username,password) values('admin', "2323423");
insert into admin(username,password) values('smass',"23423");

-- copy table structrue
create table admin_baks like admin;

-- copy table data
create table admin_bakd as (
select * from admin
);

-- variants of create table
create table admin_bakv (
ids integer not null auto_increment primary key
)
as
(
select id, username as uname, password as passd
from admin
);
