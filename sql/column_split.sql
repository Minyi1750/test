create table temp_person as (
name varchar2(100),
card varchar2(18),
phonenumber varchar2(100)
);
insert into temp_person values ('type1, typ2;type3', '526123199605623214', '13925647894;other test;13945215631');
insert into temp_person values ('type5, typ1;type4', '526123199605623214', '17945985621;phone test;15964231456');
with  T1 as (
--first step: 首先对name, phonenumber数据清洗，将所有的非字符、数字字符集替换为英文逗号。
  SELECT regexp_replace(name, '\W+', ',') AS f_name, card f_card,
         regexp_replace (phonenumber, '\W+', ',') AS f_phonenumber
  FROM temp_person
  --where card like 'G168937%'
),
T2 as (
--second step: name 以逗号为分隔符，一行成数行。
  select regexp_substr(f_name, '\w+', 1, t.lv) as s_name, f_card as s_card, f_phonenumber  as s_phonenumber
  from T1 a ,(SELECT LEVEL lv FROM DUAL CONNECT BY LEVEL < 10) t
  where t.lv <= REGEXP_COUNT (a.f_name, '\,\') + 1
),
T3 as (
--last step: phonenumber 以逗号为分隔符，一行成数行。
  select s_name as l_name, s_card as l_card, regexp_substr (b.s_phonenumber, '\w+', 1, t.lv) AS l_phonenumber 
  from T2 b, (SELECT LEVEL lv FROM DUAL CONNECT BY LEVEL < 10) t
  where t.lv <= REGEXP_COUNT (b.s_phonenumber, '\,\') + 1
)
--create table lxh_person as
select l_name, l_phonenumber
from T3 
where l_phonenumber is not null
and length(l_phonenumber) > 10
--and regexp_like(_l_phonenumber, '^[0-9]');