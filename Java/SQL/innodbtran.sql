use test;
create table account(
acc_id int(10) not null auto_increment,
acc_name varchar(20),
acc_amount decimal(5,2),
primary key(acc_id)
) engine=innodb charset=utf8;

insert into account values(null,'zhangsan',500);
insert into account values(null,"lisi",300);
select "account data" as conn;
select * from account;

start transaction;
update account set acc_amount=400 where acc_id=2;
update account set acc_amount=400 where acc_id=1;
-- before commit
select "before commit" as comm;
select * from account;

commit;
--after commit
select "after commit" as comm;
select * from account;

--rollback
rollback;
select "after rollback" as comment;
select * from account;
